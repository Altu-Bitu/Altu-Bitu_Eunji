#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//find �Լ�
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//union �Լ�
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[yp];
		parent[xp] = yp;
	}
}

//���� ��ȹ��� �湮 �������� �Ǻ��Ͽ� ��ȯ�ϴ� �Լ�
//���� ��ȹ�� ���� ���õ��� ��� ���� ���� ��, ���� ��Ʈ�� ������ �湮 ����.
bool canVisit(int m, vector<int>city) {
	int parent = findParent(city[0]);

	for (int i = 1; i < m; i++) { //���õ��� ��� ���� ���տ� ���ϴ��� �˻�
		if (parent != findParent(city[i]))
			return false;
	}
	return true;
}

int main() {
	int n, m, input;

	//�Է�
	cin >> n >> m;
	parent.assign(n + 1, -1);
	vector<int>city(m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input && i < j)
				unionInput(i, j);
		}
	}

	for (int i = 0; i < m; i++)
		cin >> city[i]; //���� ��ȹ

	//���� �� ���
	if (canVisit(m, city))
		cout << "YES\n";
	else
		cout << "NO\n";
}