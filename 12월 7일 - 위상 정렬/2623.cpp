#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//���� ����
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
	vector<int> result;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) //���������� 0�̶��
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front(); //���� ����
		q.pop();

		result.push_back(node); //���� ������ ������ ����
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i]; //���� ������ ����� ���� ������
			indegree[next]--;
			if (!indegree[next]) //���� ������ ���������� 0�̶��
				q.push(next);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt, x, y;

	//�Է�
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> indegree(n + 1, 0); //�� ������ ��������

	while (m--) {
		cin >> cnt >> x;
		while (--cnt) {
			cin >> y;
			indegree[y]++;
			graph[x].push_back(y);
			x = y;
		}
	}

	//����
	vector<int> result = topologicalSort(n, indegree, graph);

	//���� ����� ��ȯ�� ���Ϳ� ��� ������ ����Ǿ� ���� �ʴٸ� ���������� ���� ���ϴ� ��(����Ŭ �߻�)
	if (result.size() != n) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) 
		cout << result[i] << '\n';
}