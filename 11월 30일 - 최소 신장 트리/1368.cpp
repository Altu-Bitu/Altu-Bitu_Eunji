#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e6;

int prim(int v, int start, vector<vector<ci>> &graph) {
	int sum = 0;
	vector<int> dist(v + 1, INF);
	vector<bool> visited(v + 1, false);
	priority_queue<ci, vector<ci>, greater<>> pq;

	//초기화
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited[node]) //이미 방문했다면
			continue;
		sum += weight; //가중치 총합 갱신
		visited[node] = true; //방문 표시

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = graph[node][i].second;
			if (!visited[next_node] && next_weight < dist[next_node]) {
				dist[node] = next_weight;
				pq.push(make_pair(next_weight, next_node));
			}
		}

	}
	return sum;
}

int main() {
	int n, w;

	//입력
	cin >> n;
	vector <vector<ci>> graph(n + 1, vector<ci>(0));

	//우물을 팔 때 드는 비용 = 가상의 0번째 논과 i(1~n)번째 논을 연결하는 데 드는 비용
	for (int i = 1; i <= n; i++) {
		cin >> w;
		graph[i].emplace_back(0, w);
		graph[0].emplace_back(i, w);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if (w >= 1) {
				graph[i].emplace_back(j, w);
				graph[j].emplace_back(i, w);
			}
		}
	}

	//연산 및 출력
	cout << prim(n, 0, graph) << '\n';
}