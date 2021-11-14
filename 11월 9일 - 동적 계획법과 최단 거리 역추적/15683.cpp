#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n, m, ans = 64;
int cctv_size;
vector<vector<int>> room; //사무실
vector<tuple<int, int, int>> cctv; //cctv 정보: cctv 번호, 위치(행, 열)

//입력 받은 방향으로 cctv로 감시 가능한 영역 표시
void check(int row, int col, vector<int>dir, vector<vector<int>> &room) {
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == 0) { //오른쪽
			for (int j = col + 1; j < m; j++) {
				if (room[row][j] == 6)
					break; //벽이면 더이상 체크 불가.
				if (room[row][j] == 0) //빈 공간이면
					room[row][j] = 7; //cctv 감시 가능(7로 표현)
			}
		}
		else if (dir[i] == 1) { //아래쪽
			for (int j = row + 1; j < n; j++) {
				if (room[j][col] == 6)
					break;
				if (room[j][col] == 0)
					room[j][col] = 7;
			}
		}
		else if (dir[i] == 2) { //왼쪽
			for (int j = col - 1; j >= 0; j--) {
				if (room[row][j] == 6)
					break;
				if (room[row][j] == 0)
					room[row][j] = 7;
			}
		}
		else { //위쪽
			for (int j = row - 1; j >= 0; j--) {
				if (room[j][col] == 6)
					break;
				if (room[j][col] == 0)
					room[j][col] = 7;
			}
		}
	}	
}

//모든 경우의 수 구해서 최소 사각지대의 개수 구함.
void minBlind(int num, vector<vector<int>> room) {
	if (num == cctv_size) { //모든 cctv로 감시 가능한 영역을 표시했다면
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (room[i][j] == 0) //감시 못하는(사각지대) 개수 카운트
					cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int type = get<0>(cctv[num]); //몇 번 cctv인지
	int row = get<1>(cctv[num]); //cctv 위치
	int col = get<2>(cctv[num]);
	vector<vector<int>> temp = room; //원래의 사무실 상태 저장해놓을 임시 배열

	if (type == 1) { //1번 cctv
		for (int i = 0; i < 4; i++) { //가능한 cctv 방향 네가지
				//하나의 cctv는 한 방향을 가리킨다.
			vector<int>dir = { i };
			check(row, col, dir, room);
			minBlind(num + 1, room); //다음 cctv로 감시 가능 영역 체크
			room = temp; //사무실 상태 원래대로
		}
	}
	else if (type == 2) { //2번 cctv
		for (int i = 0; i < 2; i++) { //가능한 cctv 방향 두가지
		//하나의 cctv는 두 개의 방향을 가리킨다.
			vector<int>dir = { i, i + 2 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else if (type == 3) { //3번 cctv
		for (int i = 0; i < 4; i++) { //가능한 cctv 방향 네가지
			//하나의 cctv는 두 개의 방향을 가리킨다.
			vector<int>dir = { i, (i + 1) % 4 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else if (type == 4) { //4번 cctv
		for (int i = 0; i < 4; i++) { //가능한 cctv 방향 네가지 
			//하나의 cctv는 세 개의 방향을 가리킨다.
			vector<int>dir = { i, (i + 1) % 4, (i + 2) % 4 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else { //5번 cctv
		//가능한 cctv 방향은 한가지, 하나의 cctv가 모든 방향 가리킴.
		vector<int>dir = { 0,1,2,3 };
		check(row, col, dir, room);
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