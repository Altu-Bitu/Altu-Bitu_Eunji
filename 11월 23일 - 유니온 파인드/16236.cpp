//참고 블로그: https://blog.naver.com/PostView.nhn?blogId=fbfbf1&logNo=222473456076
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_TIME = 401;
const int N = 21;

vector<vector<int>> space;
vector<vector<int>> check; //방문 체크 & 이동 시간 저장 배열
int n;
int min_time; //상어가 물고기를 찾는 데 걸린 최소 시간

pair<int, int> bfs(int row, int col, int size, pair<int, int> fish_pos) {
	int dr[4] = { -1,1,0,0 }; //상, 하, 좌, 우
	int dc[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q; //bfs 탐색을 위한 큐
	q.push({ row,col }); //상어의 현재 위치 큐에 push

	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) { //인접 노드 탐색
			int nr = cr + dr[i]; //다음 방문 위치
			int nc = cc + dc[i];

			//다음 위치가 공간을 넘어가거나 이미 방문한 곳이거나 상어의 크기보다 큰 물고기가 있는 곳인 경우 continue
			if (nr < 0 || nr >= n || nc<0 || nc >= n || check[nr][nc] != -1 || space[nr][nc] > size)
				continue;

			check[nr][nc] = check[cr][cc] + 1; //nr, nc로 이동 & 시간 저장

			//만약 먹을 수 있는 물고기가 있는 위치인 경우
			if (space[nr][nc] > 0 && space[nr][nc] < size) {
				if (min_time > check[nr][nc]) { //지금까지의 최소 탐색 시간보다 더 짧은 시간을 소요했다면
					min_time = check[nr][nc]; //최소 시간 갱신
					fish_pos = { nr,nc }; //먹을 물고기 변경
				}
				else if (min_time == check[nr][nc]) { //최소 시간과 같은 시간 소요한 경우
					if (fish_pos.first > nr && fish_pos.second > nc) //왼쪽 위에 있는 경우
						fish_pos = { nr,nc };
					else if (fish_pos.first > nr) //그렇지 않지만 위쪽에 있는 경우
						fish_pos = { nr,nc }; //먹을 물고기 변경
				}
			}

			q.push({ nr,nc });
		}
	}

	return fish_pos;
}

int eating(int row, int col) {
	int time = 0;
	int size = 2;
	int cnt_fish = 0; //먹은 물고기 수
	pair<int, int> fish_pos; //아기 상어가 먹을 물고기 위치

	while (true) {
		//초기화
		min_time = MAX_TIME;
		fish_pos = { N, N };
		check.assign(n, vector<int>(n, -1));
		check[row][col] = 0;

		fish_pos = bfs(row, col, size, fish_pos); //물고기 탐색

		if (fish_pos == make_pair(N, N)) //먹을 수 있는 물고기가 없는 경우
			break;

		//먹을 수 있는 물고기 발견
		time += check[fish_pos.first][fish_pos.second]; //시간 갱신
		cnt_fish++; //먹은 물고기 수 증가

		if (cnt_fish == size) { //몸 크기와 같은 수의 물고기 먹은 경우
			size++; //몸 크기 증가
			cnt_fish = 0; //먹은 물고기 수 초기화
		}

		space[fish_pos.first][fish_pos.second] = 0; //해당 위치 물고기 제거

		row = fish_pos.first; // 아기 상어 위치 갱신
		col = fish_pos.second;;
	}

	return time;
}

int main() {
	int r, c;

	//입력
	cin >> n;
	space.assign(n, vector<int>(n));
	check.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				r = i; 
				c = j;
				space[r][c] = 0;
				check[r][c] = 0;
			}
		}
	}
	
	//연산 및 출력
	cout << eating(r, c) << "\n";
}