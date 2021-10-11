//참고 블로그
//https://jaimemin.tistory.com/1473

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int PLAYER = 9;

//각 선수가 낸 결과에 따라 점수 계산하고 base 상태 변경하는 함수
int calScore(int k, vector<bool>& base) {
	int score = 0;

	//1~3루에 있던 선수들 위치 및 이동에 따른 점수 계산
	for (int i = 2; i >= 0; i--) {
		
		if (base[i]) { //선수가 있다면
			if (i + k >= 3) { //홈으로 진루하는 경우
				score++;
			}
			else { //홈에 도달하지 못하는 경우
				base[i + k] = true;
			}
			base[i] = false;
		}
		
	}
	
	//타자 위치
	if (k == 4)
		score++;
	else {
		base[k - 1] = true;
	}

	return score;
}

//게임 후 점수 반환하는 함수
int playGame(int n, vector<vector<int>> inning, vector<int> order) {
	int hitter = 0; //몇번째 타자가 쳐야 하는지 저장
	vector<bool> base(3, 0);
	int score = 0;
	int idx = 0; //몇번째 이닝인지
	
	//4번 타자에 1번 선수 저장
	order.insert(order.begin() + 3, 0);

	//n이닝 동안 게임 진행
	while (idx < n) {
		int out = 0; //아웃 수
		while (out < 3) {
			int play = inning[idx][order[hitter]]; //이번에 얻을 결과
			switch (play) {
			case 0:
				out++;
				break;
			case 1: //안타
				score += calScore(1, base);
				break;
			case 2: //2루타
				score += calScore(2, base);
				break;
			case 3: //3루타
				score += calScore(3, base);
				break;

			case 4: //홈런
				score += calScore(4, base);
				break;		
			}

			//다음 타자 준비
			hitter = (hitter + 1) % 9;
		}

		//베이스 초기화
		for (int i = 0; i < 3; i++)
			base[i] = false;

		idx++; //이닝 하나 추가
	}

	return score;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	//입력
	cin >> n;
	vector<vector<int>>inning(n, vector<int>(PLAYER));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < PLAYER; j++)
			cin >> inning[i][j];
	}

	//연산
	int score = 0;
	vector<int> order = { 1,2,3,4,5,6,7,8 }; //타순
	do { //첫번째 선수는 이미 순서가 정해져 있으므로 제외하고 나머지 순서 지정
		int temp = playGame(n, inning, order);
		score = max(temp, score);
	} while (next_permutation(order.begin(), order.end()));

	//출력
	cout << score << '\n';
}