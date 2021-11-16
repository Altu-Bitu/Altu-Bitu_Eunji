#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n, m, ans = 64;
int cctv_size;
vector<vector<int>> room; //사무실
vector<tuple<int, int, int>> cctv; //cctv 정보: cctv 번호, 위치(행, 열)
vector<vector<vector<int>>>cctv_dir = { //cctv 종류별 방향 가짓수 & 오른쪽(0), 아래(1), 왼쪽(2), 위(3)
	{{0},{1},{2},{3}}, //1번
	{{0,2},{1,3}}, //2번
	{{0,1},{1,2},{2,3},{3,0}}, //3번
	{{0,1,2},{1,2,3},{2,3,0},{3,0,1}}, //4번
	{{0,1,2,3}} }; //5번

//입력 받은 방향으로 cctv로 감시 가능한 영역 표시
void check(int row, int col, vector<int>dir, vector<vector<int>>& room) {
	int dr[4] = { 0,1,0,-1 }; //오른쪽(0), 아래(1), 왼쪽(2), 위(3)
	int dc[4] = { 1,0,-1,0 };

	for (int i = 0; i < dir.size(); i++) {
		int cr = row + dr[dir[i]];
		int cc = col + dc[dir[i]];

		while (cr >= 0 && cr < n && cc >= 0 && cc < m && room[cr][cc] != 6) {
			if (room[cr][cc] == 0)
				room[cr][cc] = 7;
			cr += dr[dir[i]];
			cc += dc[dir[i]];
		}
	}

}

//사각지대 개수 카운트
int numBlind(vector<vector<int>> &room) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (room[i][j] == 0) //감시 못하는(사각지대) 개수 카운트
				cnt++;
		}
	}
	return cnt;
}

//모든 경우의 수 구해서 최소 사각지대의 개수 구함.
void minBlind(int num, vector<vector<int>> room) {
	if (num == cctv_size) { //모든 cctv로 감시 가능한 영역을 표시했다면
		int temp = numBlind(room);
		ans = min(ans, temp);
		return;
	}

	int type = get<0>(cctv[num]); //몇 번 cctv인지
	int row = get<1>(cctv[num]); //cctv 위치
	int col = get<2>(cctv[num]);
	vector<vector<int>> temp = room; //원래의 사무실 상태 저장해놓을 임시 배열

	for (int i = 0; i < cctv_dir[type - 1].size(); i++) {
		check(row, col, cctv_dir[type - 1][i], room);
		minBlind(num + 1, room);
		room = temp;
	}
}

int main() {
	//입력
	cin >> n >> m;
	room.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5) { //cctv를 입력받으면
				cctv_size++;
				cctv.push_back({ room[i][j],i,j }); //cctv 정보를 목록에 추가
			}
		}
	}

	//연산
	minBlind(0, room);

	//출력
	cout << ans << '\n';
}