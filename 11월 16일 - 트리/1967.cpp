#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> tree; //Ʈ��
vector<bool> visited; //�湮üũ
int ans = 0; //��
int far_node = 0; //������ �� �� ���

//dfs �Լ�
void dfs(int node, int sum) {
	if (visited[node]) //�̹� �湮�� �����
		return;

	visited[node] = true; //�湮 ǥ��

	if (ans < sum) { //��������� �Ÿ����� �� �Ÿ��� �� �����
		ans = sum; //�Ÿ� ����
		far_node = node; //��� ����
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i].first;
		int next_sum = sum + tree[node][i].second;
		dfs(next_node, next_sum);
	}

	visited[node] = false; //�湮 ǥ�� ����
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
	//��Ʈ ��忡�� ���� �ָ� �ִ� ���� ��� ã��
	dfs(1, 0);

	//������ ã�� ���� ��忡�� ���� �� ��� ã�� & �׶��� �Ÿ�(����) ���ϱ�
	dfs(far_node, 0);

	//���
	cout << ans << '\n';
}