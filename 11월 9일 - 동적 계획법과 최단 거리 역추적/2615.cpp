#include <iostream>
#include<vector>

using namespace std;
const int SIZE = 19;

//바둑알이 바둑판에 올라가 있는 경우 그 위치의 주변을 탐색 후 승부가 나는지 반환하는 함수
int whoWin(int row, int col, vector<vector<int>>& board) {
	int ans = 0; //승부가 나지 않았을 경우 0 반환
	int current = board[row][col]; //현재 위치에 있는 바둑알의 종류
	//바둑알이 놓일 수 있는 방향 (오른쪽, 아래, 오른쪽 아래 대각선, 오른쪽 위 대각선)
	int dr[4] = { 0,1,1,-1 };
	int dc[4] = { 1,0,1,1 };

	//방향마다 오목을 이루는지 확인
	for (int k = 0; k < 4; k++) {
		int cr = row; //현재 위치
		int cc = col;

		//탐색 시작 전 탐색 방향과 반대 방향에 있는 바둑알의 종류 확인
		//만약 종류가 같다면 이전에 검사한 방향임
		int pr = cr - dr[k];
		int pc = cc - dc[k];
		if (pr >= 0 && pr < SIZE && pc >= 0 && pc < SIZE && board[pr][pc] == current)
			continue; //다른 방향으로 탐색

		int cnt = 1; //같은 바둑알이 연달아 몇개 나오는지 카운트해서 저장할 변수
		for (int i = 0; i < 5; i++) { //5개까지 확인(총 6개)
			int nr = cr + dr[k];
			int nc = cc + dc[k];
			if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && board[nr][nc] == current) {
				cr = nr;
				cc = nc;
				cnt++;
			}
			else
				break;
		}

		if (cnt == 5) { //만약 같은 바둑알이 5개 나왔다면
			ans = current; //ans 갱신
			break; //더이상 탐색하지 않아도 됨
		}
	}
	return ans;
}

//게임 결과 반환
vector<int> game(vector<vector<int>>&board) {
	vector<int>result(3, 0); //0: 이긴 바둑알의 종류, 1: 바둑알의 가로줄 변호, 2: 세로줄 번호
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != 0) { //i행 j열 위치에 바둑알이 놓여있다면
				int winner = whoWin(i, j,board); //승부가 나는지 확인
				if (winner != 0) { //승부가 났다면
					result[0] = winner;
					result[1] = i + 1; //0행 0열부터 시작하므로 1 더함
					result[2] = j + 1;
					return result;
				}
			}
		}
	}
	return result;
}

int main() {
	vector<vector<int>>board(SIZE, vector<int>(SIZE, 0)); //바둑판

	//입력
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cin >> board[i][j];
	}

	//연산
	vector<int>result = game(board);

	//출력
	if (result[0] == 0)
		cout << result[0] << '\n';
	else
		cout << result[0] << '\n' << result[1] << ' ' << result[2] << '\n';
}