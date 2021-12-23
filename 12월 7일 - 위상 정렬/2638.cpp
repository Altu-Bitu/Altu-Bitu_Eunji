#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = { -1,0,1,0 }; //상하좌우 방향
int dc[4] = { 0,1,0,-1 };

//외부, 내부 공기 구별 초기화
void initOutside(int n, int m, vector<vector<int>> &paper) {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	paper[0][0] = -1;
	 
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i]; //주변 위치
			int nc = cc + dc[i];

			//다음 위치에 있는 것이 치즈가 아닌 경우
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && paper[nr][nc] == 0) {
				q.push({ nr,nc }); //외부공기와 맞닿아 있으므로 외부 공기임
				paper[nr][nc] = -1; //외부공기 값 -1로 변경
			}
		}
	}
}

//외부 공기 값 -1로 바꾸는 함수
void checkOutside(int n, int m, vector<vector<int>> &paper, queue<pair<int, int>> q) {
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i]; //주변 위치
			int nc = cc + dc[i];

			//다음 위치에 있는 것이 치즈가 아닌 경우
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && paper[nr][nc] == 0) {
				q.push({ nr,nc }); //외부공기와 맞닿아 있으므로 외부 공기임
				paper[nr][nc] = -1; //외부공기 값 -1로 변경
			}
		}
	}
}

//녹은 치즈를 외부 공기로 바꿔주기
void chageCheeseToAir(vector<vector<int>> &paper, queue<pair<int, int>> q){
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		paper[cr][cc] = -1;
	}
}


//외부와 맞닿은 면의 개수 반환하는 함수
int cntTouch(int n, int m, int row, int col, vector<vector<int>> &paper) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) { //주변 탐색
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (paper[nr][nc] == -1) //외부 공기와 맞닿았다면
			cnt++;
	}

	return cnt;
}
 

//치즈가 녹는 데 걸리는 시간 구하는 함수
int meltingTime(int n, int m, vector<vector<int>> &paper) {
	int ans = 0; //걸리는 시간
	while (true) {
		queue<pair<int, int>> q;
		bool empty = true; //모눈종이에 치즈가 있는지 표시하기 위한 변수
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) { //치즈가 있는 칸 찾아서 녹을지 검사
				if (paper[i][j] != 1)
					continue;
				empty = false; //치즈가 있음
				int cnt = cntTouch(n, m, i, j, paper);
				if (cnt >= 2) {
					paper[i][j] = 0;
					q.push({ i,j });
				}
			}
		}

		if (empty) //치즈가 없다면
			break; //while문 탈출
		
		chageCheeseToAir(paper, q);
		checkOutside(n, m, paper, q); //외부공기 갱신
		ans++; //1시간 지남
	}
	
	return ans;
}
	

int main() {
	int n, m;
	
	//입력
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	//연산 및 출력
	initOutside(n, m, paper); //외부 공기와 내부 공기 구별(초기화)
	cout << meltingTime(n, m, paper) << '\n';
}