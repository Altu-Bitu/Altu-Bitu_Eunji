#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//Union ����
//����Ŭ �߻��ϸ� true ��ȯ
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)  //�̹� ���� ���տ� �ִ� ��� -> ����Ŭ �߻�
		return true;

	if (parent[xp] < parent[yp]) { //���ο� ��Ʈ�� xp
		parent[xp] += parent[yp]; //parent �迭 ����
		parent[yp] = xp;
	}
	else { //���ο� ��Ʈ�� yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	int ans = 0;

	//�Է�
	cin >> n >> m;
	parent.assign(n, -1);

	//����
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (unionInput(a, b)) { //����Ŭ �߻�
			ans = i; //���°���� �����ϰ� �ݺ��� Ż��
			break;
		}
	}

	//���
	cout << ans << '\n';
}