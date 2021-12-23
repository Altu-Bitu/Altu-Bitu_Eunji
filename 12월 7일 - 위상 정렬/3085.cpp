#include <iostream>
#include <vector>

using namespace std;

//가로로 연속 캔디 세는 함수
int countCol(int n, vector<vector<char>>& candy) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int length = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) //인접한(양옆) 두 캔디의 색이 같다면
				length++; //길이 추가
			else { //그렇지 않다면
				ans = max(length, ans); //최대 길이 갱신
				length = 1;
			}
		}
		ans = max(ans, length);
	}

	return ans;
}

 //세로로 연속 캔디 세는 함수
int countRow(int n, vector<vector<char>>& candy) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int length = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) //인접한(위아래) 두 캔디의 색이 같다면
				length++;
			else {
				ans = max(length, ans);
				length = 1;
			}
		}
		ans = max(ans, length);
	}
	return ans;
}

//연속 캔디의 최대 길이 구하는 함수
int maxCount(int n, vector<vector<char>>& candy) {
	int ans = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] != candy[i][j + 1]) { //옆으로 인접한 캔디 색이 다르다면
				swap(candy[i][j], candy[i][j + 1]); //위치 바꿈
				temp = max(countCol(n, candy), countRow(n, candy)); //가장 긴 캔디의 연속 길이 구하기
				ans = max(ans, temp);
				swap(candy[i][j], candy[i][j + 1]); //제자리로
			}
			
			if (candy[j][i] != candy[j + 1][i]) { //위아래로 인접한 캔디 색이 다르다면
				swap(candy[j][i], candy[j + 1][i]);
				temp = max(countCol(n, candy), countRow(n, candy));
				ans = max(ans, temp);
				swap(candy[j][i], candy[j + 1][i]);
			}
		}
	}
	return ans;
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<vector<char>> candy(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> candy[i][j];
	}
	
	//연산 및 출력
	cout << maxCount(n, candy) << '\n';
}