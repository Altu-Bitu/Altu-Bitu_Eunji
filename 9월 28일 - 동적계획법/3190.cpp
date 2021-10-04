#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct direction_info {
	int time;
	char direction;
};

//게임이 끝났는지
bool ifContinue(int n, queue<pair<int, int>> snake, vector<vector<int>> board, int dx[], int dy[], int dir) {
	int x, y;
	//한 칸 앞으로 이동했을 때 뱀 머리의 위치
	y = snake.back().first + dy[dir]; //행
	x = snake.back().second + dx[dir]; //열

	if (x > n || y > n || x < 1 || y < 1) //벽에 머리가 닿을 경우
		return false;
	if (board[y][x] == 2) //뱀의 몸에 머리가 닿을 경우
		return false;

	return true;
}

//언제 게임이 끝나는지
int endTime(int n, vector<vector<int>> &board, vector<direction_info>dir_info) {
	int time = 0; //종료 시간
	queue<pair<int, int>> snake; //뱀의 위치(좌표) 저장, 큐 앞쪽: 꼬리, 뒤쪽: 머리
	pair<int, int> head = { 1,1 }; //머리 좌표
	snake.push(head); //큐 초기 설정

	// 인덱스별로 이동가능한 4가지 방향 저장
	// 오른쪽 회전-> 인덱스 1 증가, 왼쪽 회전 -> 인덱스 1 감소
	int dx[4] = { -1, 0, 1 , 0 }; //좌우(열 방향)
	int dy[4] = { 0, -1, 0, 1 }; //상하(행 방향)
	int dir = 2; //처음에는 오른쪽으로 이동하므로 dx, dy배열에서 오른쪽으로 이동하는 인덱스인 2을 저장

	board[head.first][head.second] = 2; //뱀의 머리가 있는 위치는 2로 표시

	int dir_idx = 0; //방향 전환 벡터의 원소 접근 시 사용할 인덱스 값


	while (ifContinue(n, snake, board, dx, dy, dir)) {
		time++;
		//머리 이동
		head.first = snake.back().first + dy[dir];
		head.second = snake.back().second + dx[dir];

		if (board[head.first][head.second] == 1) { //사과가 있다면
			board[head.first][head.second] = 2; //2(뱀)로 값 변경
			snake.push(head); //뱀 위치에 현재 머리 위치 넣기
		}
		else if(board[head.first][head.second] == 0){ //아무 것도 없다면
			//현재 머리 위치 뱀 위치에 추가
			board[head.first][head.second] = 2;
			snake.push(head);

			//꼬리 부분 뱀 위치에서 제거
			pair<int, int> tail;
			tail = snake.front();
			snake.pop();
			board[tail.first][tail.second] = 0; // 보드판에서 꼬리 부분 값 0으로 변경
		}
		
		if (time == dir_info[dir_idx].time) { //방향 전환하는 time이면
			if (dir_info[dir_idx].direction == 'D') //오른쪽으로 회전
				dir = (dir + 1) % 4;
			if (dir_info[dir_idx].direction == 'L') //왼쪽으로 회전
				dir = (dir - 1 + 4) % 4;
			
			if (dir_idx < dir_info.size() - 1)
				dir_idx++;
		}
	}
	time++; //벽 혹은 몸에 부딪히는 경우에도 뱀이 기어야 하므로 1초 추가
	return time;
}

int main() {
	int n, k, l;

	//입력
	cin >> n >> k;
	vector<vector<int>>board(n + 1, vector<int>(n + 1, 0)); //보드(아무 것도 없으면 0, 사과 1, 뱀이 있다면 2)
	
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; //사과가 있는 위치는 1로 표시
	}

	cin >> l;
	vector<direction_info> dir_info(l);
	for (int i = 0; i < l; i++) {
		cin >> dir_info[i].time >> dir_info[i].direction;
	}

	cout << endTime(n, board, dir_info)<<'\n';


}