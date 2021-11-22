#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> tree;

//���������� �Ǵ�
bool isCutPoint(int node) {
	if (tree[node].size() >= 2) //2�� �̻��� ������ ����� �����̶�� ��������
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;

	//�Է�
	cin >> n;
	tree.assign(n + 1,vector<int>(0));

	int cnt = n - 1;
	while (cnt--) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cin >> q;
	while (q--) {
		int t, k;
		cin >> t >> k;

		//���� �� ���
		if (t == 1) {
			if (isCutPoint(k))
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else //Ʈ���� ������ ��� ������
			cout << "yes\n";
		
	}
}