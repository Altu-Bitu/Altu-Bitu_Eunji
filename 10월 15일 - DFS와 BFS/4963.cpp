#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//하나의 섬을 찾아 방문 표시(map의 값을 2로 변경)하는 함수
vector<vector<int>> bfs(int w, int h, int r, int c, vector<vector<int>> map) {
	queue<pair<int, int>> q; //탐색을 위한 큐
	int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; //위, 아래, 오른쪽, 왼쪽, 오른쪽 위, 왼쪽 위, 오른쪽 아래, 왼쪽 아래
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
	return map;
}

//섬의 개수 반환하는 함수
int numOfIsland(int w, int h, vector<vector<int>> &map) {
	int cnt = 0; //섬의 개수
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) { //아직 방문하지 않은 곳이라면
				map = bfs(w, h, i, j, map);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int w, h;

	while (true) {
		//입력
		cin >> w >> h;
		if (w == 0 && h == 0) //반복 종료 조건
			break;
		
		vector<vector<int>> map(h, vector<int>(w, 0)); //지도
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//연산 및 출력
		cout << numOfIsland(w, h, map) << '\n';
	}
}