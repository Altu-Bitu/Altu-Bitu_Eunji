#include <iostream>
#include <vector>

using namespace std;

//역추적
vector<int> back(int x, vector<int>& path) {
	vector<int>result(0);
	while (x != -1) {
		result.push_back(x);
		x = path[x];
	}
	return result;
}

int minCount(int n, vector<int> &path) {
	vector<int>dp(n + 1, 0); //dp 배열

	for (int i = 2; i <= n; i++) {
		if (i % 2 != 0 && i % 3 != 0) { //2, 3 모두로 안 나눠떨어진다면 1을 빼야 한다.
			dp[i] = dp[i - 1] + 1; // 1을 뺀 수의 연산 횟수에 1을 더함(1을 빼는 연산을 했으므로)
			path[i] = i - 1; // 경로 저장
		}
		if (i % 2 == 0 && i % 3 == 0) { //2로도, 3으로도 나누어 떨어진다면
			if (dp[i / 2] < dp[i / 3]) { //두 수로 나눈 몫 중 연산 횟수가 더 적은 수를 선택해야 함.
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
			else {
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
		}
		else if (i % 2 == 0) { //2로만 나누어 떨어진다면
			if (dp[i / 2] < dp[i - 1]) { //2로 나눈 수와 1을 뺀 수 중 연산 횟수가 적은 수 선택
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
			else {
				dp[i] = dp[i - 1] + 1;
				path[i] = i - 1;
			}
		}
		else if (i % 3 == 0) { //3으로만 나누어 떨어진다면
			if (dp[i / 3] < dp[i - 1]) { //3으로 나눈 수와 1을 뺀 수 중 연산 횟수가 더 적은 수 선택
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
			else {
				dp[i] = dp[i - 1] + 1;
				path[i] = i - 1;
			}
		}
	}
	return dp[n];
}

int main() {
	int n;
	
	//입력
	cin >> n;
	vector<int>path(n + 1, -1); //경로 저장할 배열

	//연산
	int ans = minCount(n, path);
	vector<int>result = back(n, path);
	
	//출력
	cout << ans << '\n';
	for (int i = 0; i <result.size(); i++)
		cout << result[i] << ' ';
}