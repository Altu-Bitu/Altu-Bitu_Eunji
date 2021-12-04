#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> space;

pair<int, int> moveBlock(int height, int n, int m, int b) {
	pair<int, int> info = { 0, b };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = height - space[i][j]; //�ʿ��� ��� ��
			info.second -= num; //���� ��Ͽ��� �ʿ��� ��� �� ����
			if (num < 0) //�ʿ��� ��� ���� ������ ���(����� �����ϴ� ���)
				info.first = info.first + (-2) * num; //�ð� ����
			else if (num > 0) //��� �߰��ϴ� ���
				info.first += num; //�ð� ����
		}
	}
	return info;
}

pair<int, int> ground(int n, int m, int b, int max_height, int min_height) {
	pair<int, int> ans = {2e8, 0}; //�ð�, ���� ��

	//�ּ� ���̺��� �ִ� ���̱��� ��� �ɸ��� �ð� �˻�
	for (int i = min_height; i <= max_height; i++) {

		pair<int, int> temp = moveBlock(i, n, m, b);
		
		if (temp.second >= 0) { //���� ����� 0�� �̻��� ���
			if (temp.first <= ans.first){ //���� ����
				ans.first = temp.first;
				ans.second = max(ans.second, i);
			}
		}
	}
	return ans;
}

int main() {
	int n, m, b;
	int max_height = 0;
	int min_height = 256;

	//�Է�
	cin >> n >> m >> b;
	space.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
			max_height = max(max_height, space[i][j]);
			min_height = min(min_height, space[i][j]);
		}
	}

	//����
	pair<int, int> ans = ground(n, m, b, max_height, min_height);

	//���
	cout << ans.first << ' ' << ans.second << '\n';
}