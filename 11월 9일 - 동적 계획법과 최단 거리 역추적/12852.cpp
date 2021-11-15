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
		dp[i] = dp[i - 1] + 1; //우선 1을 빼는 연산 수행
		path[i] = i - 1;
	
		if (i % 2 == 0 && dp[i / 2] < dp[i] - 1) { //2로 나누어 떨어지고 1을 빼는 것보다 연산 횟수가 적다면
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i / 3] < dp[i] - 1) { //3으로 나누어 떨어지고 1을 빼는 것(+ 2로 나누는 것)보다 연산 횟수가 적다면
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
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