#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> tree; //Ʈ��
vector<bool> visited; //�湮üũ
int ans = 0; //��

//���� ���ϴ� �Լ�
void maxDistance(int node, int sum) {
	if (tree[node].size() == 1) { //��Ʈ ��忡 �����ϸ�
		ans = max(sum, ans); //�ִ� ����
		return;
	}

	//��忡 ����� ������ ����ŭ Ž��
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first; //������ Ž���� ���
		if (visited[next]) { //�湮�� �����
			continue;
		}
		visited[node] = true; //���� ��� �湮 ǥ��
		sum += tree[node][i].second; //��� ���� ����

		maxDistance(next, sum); //���� ��� �湮

		visited[node] = false; //�湮 �� �湮üũ ����
		sum -= tree[node][i].second; //��� ���� �������
	}
}

int main() {
	int n;

	//�Է�
	cin >> n;
	tree.assign(n + 1, vector<pair<int, int>>(0));
	visited.assign(n + 1, false);
	int cnt = n - 1;
	while (cnt--) {
		int a, b, w;
		cin >> a >> b >> w;
		tree[a].emplace_back(b, w);
		tree[b].emplace_back(a, w);
	}

	//����
	//���� ��忡�� ����
	while (n >= 1) {
		if (tree[n].size() == 1) {
			visited[n] = true;
			int next = tree[n][0].first;
			int weight = tree[n][0].second;
			maxDistance(next, weight);
		}
		n--;
	}

	//���
	cout << ans << '\n';
}