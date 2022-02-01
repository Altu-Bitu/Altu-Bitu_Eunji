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

	//�ʱ�ȭ
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited[node]) //�̹� �湮�ߴٸ�
			continue;
		sum += weight; //����ġ ���� ����
		visited[node] = true; //�湮 ǥ��

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

	//�Է�
	cin >> n;
	vector <vector<ci>> graph(n + 1, vector<ci>(0));

	//�칰�� �� �� ��� ��� = ������ 0��° ��� i(1~n)��° ���� �����ϴ� �� ��� ���
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

	//���� �� ���
	cout << prim(n, 0, graph) << '\n';
}