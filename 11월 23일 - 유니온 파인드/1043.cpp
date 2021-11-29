#include <iostream>
#include <vector>

using namespace std;

vector<int>parent;
vector<bool>know; //������ �˰� ������ true

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;

	if (know[xp] || know[yp]) //�� ����̶� �ȴٸ� �������� ���� ���� (��Ƽ ������ ��� ��ΰ� ������ �˰� ��)
		know[xp] = know[yp] = true;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int cntParty(vector<vector<int>> party, int m) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int p = findParent(party[i][0]); //i��° ��Ƽ�� ������ ������� ���տ����� ��Ʈ

		if (!know[p]) //���� ��Ʈ�� �ش��ϴ� ���(���� ��Ƽ�� ������ ���)�� ������ ���� ���Ѵٸ� ��ǳ ��� ��.
			cnt++;
	}
	return cnt;
}

int main() {
	int n, m, num;
	int cnt_know;

	//�Է�
	cin >> n >> m;
	parent.assign(n + 1, -1);
	know.assign(n + 1, false);
	vector<vector<int>> party(m); //��Ƽ���� ������ ��� ����

	cin >> cnt_know;
	while (cnt_know--) { //�˰� �ִ� ��� �Է¹޾Ƽ� know ����
		cin >> num;
		know[num] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> num; //i��° ��Ƽ�� num���� ��� ����
		for (int j = 0; j < num; j++) {
			int input; //������ ����� ��ȣ
			cin >> input;
			party[i].push_back(input); //��Ƽ ��ܿ� �ֱ�
		}
		for (int j = 0; j < num - 1; j++) //���� ��Ƽ�� ������ ����鳢�� �ϳ��� �������� ����.
			unionInput(party[i][j], party[i][j + 1]);
	}

	//���� �� ���
	cout << cntParty(party, m) << '\n';
}