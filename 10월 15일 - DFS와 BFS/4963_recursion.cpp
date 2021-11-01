#include <iostream>
#include <vector>

using namespace std;
int w, h;
vector<vector<int>> map;
int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //방향
int dc[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

//재귀함수로 구현한 DFS
void dfsRecur(int r, int c) {
	map[r][c]++; //방문 표시
	for (int i = 0; i < 8; i++) { //주변 탐색
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) //아직 방문하지 않은 곳이라면 계속 탐색
			dfsRecur(nr, nc);
	}
}

int main() {
	while (true) {
		//입력
		cin >> w >> h;
		if (w == 0 && h == 0) //반복 종료 조건
			break;

		map.assign(h, vector<int>(w, 0)); //지도
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//연산 및 출력
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) { //아직 방문하지 않은 곳이라면
					dfsRecur(i, j);
					cnt++; //섬의 개수 증가
				}
			}
		}
		cout << cnt << '\n';
	}
}