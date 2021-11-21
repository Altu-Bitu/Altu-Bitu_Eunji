#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> room;

int cntClean(int n, int m, int row, int col, int dir) {
	int cnt = 0; //청소한 칸의 개수
	int dr[4] = { -1,0,1,0 }; //북~서(시계방향)
	int dc[4] = { 0,1,0,-1 };

	while (true) {
		if (room[row][col] == 0) { //현재 청소하지 않은 칸에 있다면
			cnt++;
			room[row][col] = 2; //청소 표시
		}

		int current_dir = dir;
		do { //왼쪽으로 회전, 청소를 하지 않은 칸을 찾거나 원래 방향으로 돌아오면 회전 중지
			dir = (dir - 1 + 4) % 4;
		} while (dir != current_dir && room[row + dr[dir]][col + dc[dir]] != 0);
		
		if (dir == current_dir && room[row + dr[dir]][col + dc[dir]] != 0) { //원래 방향으로 돌아옴 && 원래 방향 쪽 칸 청소가 안 되어 있다면
			if (room[row + dr[(dir + 2) % 4]][col + dc[(dir + 2) % 4]] == 1) //뒤쪽 방향이 벽이면
				break; //작동 중단
			row -= dr[dir]; //뒤쪽이 벽이 아니면 후진
			col -= dc[dir];
			continue;
		}

		//지금 향한 방향 쪽 칸이 청소가 되어 있지 않은 경우임
		row += dr[dir]; //해당 방향으로 한 칸 전진
		col += dc[dir];
	}

	return cnt;
}

int main() {
	int n, m, r, c, d;

	//입력
	cin >> n >> m >> r >> c >> d;
	room.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> room[i][j];
	}

	cout << cntClean(n, m, r, c, d) << '\n';
}