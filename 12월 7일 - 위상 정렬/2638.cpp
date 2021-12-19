#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = { -1,0,1,0 }; //상하좌우 방향
int dc[4] = { 0,1,0,-1 };

//외부 공기 값 -1로 바꿔서 반환해주는 함수
vector<vector<int>> checkOutside(int n, int m, vector<vector<int>> paper) {
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
	return paper;
}

//외부와 맞닿은 면의 개수 반환하는 함수
int cntTouch(int n, int m, int row, int col, vector<vector<int>>& paper) {
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
	vector<vector<int>> temp; //외부 공기와 내부 공기를 구별한 것을 저장할 임시 배열

	while (true) {
		temp = checkOutside(n, m, paper); //외부 공기와 내부 공기 구별
		bool empty = true; //모눈종이에 치즈가 있는지 표시하기 위한 변수
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) { //치즈가 있는 칸 찾아서 녹을지 검사
				if (temp[i][j] != 1)
					continue;
				empty = false; //치즈가 있음
				int cnt = cntTouch(n, m, i, j, temp); 
				if (cnt >= 2)
					paper[i][j] = 0; //외부공기와 맞닿은 면의 개수 2개 이상이라면 녹는다(공기로 표시)
			}
		}

		if (empty) //치즈가 없다면
			break; //while문 탈출

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
	cout << meltingTime(n, m, paper) << '\n';
}