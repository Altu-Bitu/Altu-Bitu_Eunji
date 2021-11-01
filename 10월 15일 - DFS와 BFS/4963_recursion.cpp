#include <iostream>
#include <vector>

using namespace std;
int w, h;
vector<vector<int>> map;
int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //����
int dc[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

//����Լ��� ������ DFS
void dfsRecur(int r, int c) {
	map[r][c]++; //�湮 ǥ��
	for (int i = 0; i < 8; i++) { //�ֺ� Ž��
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) //���� �湮���� ���� ���̶�� ��� Ž��
			dfsRecur(nr, nc);
	}
}

int main() {
	while (true) {
		//�Է�
		cin >> w >> h;
		if (w == 0 && h == 0) //�ݺ� ���� ����
			break;

		map.assign(h, vector<int>(w, 0)); //����
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//���� �� ���
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) { //���� �湮���� ���� ���̶��
					dfsRecur(i, j);
					cnt++; //���� ���� ����
				}
			}
		}
		cout << cnt << '\n';
	}
}