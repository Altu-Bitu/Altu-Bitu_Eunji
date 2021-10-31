#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�ϳ��� ���� ã�� �湮 ǥ��(map�� ���� 2�� ����)�ϴ� �Լ�
void bfs(int w, int h, int r, int c, vector<vector<int>>& map) {
	queue<pair<int, int>> q; //Ž���� ���� ť
	int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; //��, �Ʒ�, ������, ����, ������ ��, ���� ��, ������ �Ʒ�, ���� �Ʒ�
	int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) {
				map[nr][nc] += 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}

//���� ���� ��ȯ�ϴ� �Լ�
int numOfIsland(int w, int h, vector<vector<int>> &map) {
	int cnt = 0; //���� ����
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) { //���� �湮���� ���� ���̶��
				bfs(w, h, i, j, map);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int w, h;

	while (true) {
		//�Է�
		cin >> w >> h;
		if (w == 0 && h == 0) //�ݺ� ���� ����
			break;
		
		vector<vector<int>> map(h, vector<int>(w, 0)); //����
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//���� �� ���
		cout << numOfIsland(w, h, map) << '\n';
	}
}