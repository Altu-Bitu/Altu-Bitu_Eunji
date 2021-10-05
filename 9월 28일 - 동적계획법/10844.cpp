#include <iostream>
#include <vector>
using namespace std;

int stairNum(int n, vector<vector<int>> dp) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) //j가 0이면 이웃한 수가 오른쪽(j+1) 밖에 없음
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) //j가 9면 이웃한 수가 왼쪽(j-1) 밖에 없음
				dp[i][j] = dp[i - 1][j - 1];
			else // 그 외에는 이전 dp에서의 이웃한 수들의 횟수를 더함
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	//길이가 n(dp[n])일 때, 0~9가 나온 횟수 전부를 더하면 길이가 n인 계단 수의 총 개수를 구할 수 있음
	for (int i = 0; i <= 9; i++)
		cnt = (cnt + dp[n][i]) % 1000000000;

	return cnt;
}

int main() {
	int n;

	//입력
	cin >> n;
	//dp[i][j]: 길이가 i인 모든 계단 수들에서 j가 나온 횟수
	vector<vector<int>> dp(n + 1, vector<int>(10, 0));
	
	//dp[1] 초기화
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	//출력
	cout << stairNum(n, dp) << '\n';
}