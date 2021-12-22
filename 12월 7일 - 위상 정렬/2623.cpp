#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상 정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
	vector<int> result;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) //진입차수가 0이라면
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front(); //현재 정점
		q.pop();

		result.push_back(node); //현재 정점을 순서에 삽입
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i]; //현재 정점에 연결된 다음 정점들
			indegree[next]--;
			if (!indegree[next]) //다음 정점의 진입차수가 0이라면
				q.push(next);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt, x, y;

	//입력
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> indegree(n + 1, 0); //각 정점의 진입차수

	while (m--) {
		cin >> cnt >> x;
		while (--cnt) {
			cin >> y;
			indegree[y]++;
			graph[x].push_back(y);
			x = y;
		}
	}

	//연산
	vector<int> result = topologicalSort(n, indegree, graph);

	//연산 결과로 반환된 벡터에 모든 가수가 저장되어 있지 않다면 위상정렬을 하지 못하는 것(사이클 발생)
	if (result.size() != n) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) 
		cout << result[i] << '\n';
}