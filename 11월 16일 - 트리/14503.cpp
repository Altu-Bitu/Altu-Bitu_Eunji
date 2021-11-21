#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> room;

int cntClean(int n, int m, int row, int col, int dir) {
	int cnt = 0; //û���� ĭ�� ����
	int dr[4] = { -1,0,1,0 }; //��~��(�ð����)
	int dc[4] = { 0,1,0,-1 };

	while (true) {
		if (room[row][col] == 0) { //���� û������ ���� ĭ�� �ִٸ�
			cnt++;
			room[row][col] = 2; //û�� ǥ��
		}

		int current_dir = dir;
		do { //�������� ȸ��, û�Ҹ� ���� ���� ĭ�� ã�ų� ���� �������� ���ƿ��� ȸ�� ����
			dir = (dir - 1 + 4) % 4;
		} while (dir != current_dir && room[row + dr[dir]][col + dc[dir]] != 0);
		
		if (dir == current_dir && room[row + dr[dir]][col + dc[dir]] != 0) { //���� �������� ���ƿ� && ���� ���� �� ĭ û�Ұ� �� �Ǿ� �ִٸ�
			if (room[row + dr[(dir + 2) % 4]][col + dc[(dir + 2) % 4]] == 1) //���� ������ ���̸�
				break; //�۵� �ߴ�
			row -= dr[dir]; //������ ���� �ƴϸ� ����
			col -= dc[dir];
			continue;
		}

		//���� ���� ���� �� ĭ�� û�Ұ� �Ǿ� ���� ���� �����
		row += dr[dir]; //�ش� �������� �� ĭ ����
		col += dc[dir];
	}

	return cnt;
}

int main() {
	int n, m, r, c, d;

	//�Է�
	cin >> n >> m >> r >> c >> d;
	room.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> room[i][j];
	}

	cout << cntClean(n, m, r, c, d) << '\n';
}