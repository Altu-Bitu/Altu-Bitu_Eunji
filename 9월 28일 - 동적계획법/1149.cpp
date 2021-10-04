#include <iostream>
#include <vector>

using namespace std;


int minCost(int n, vector<vector<int>>cost) {
	//dp[i][0~2]: i번째 집을 각각 red, green, blue로 지었을 때의 최소 비용
	vector<vector<int>> dp(n, vector<int>(3, 1001));

	//0번(첫번째)집
	dp[0][0] = cost[0][0], dp[0][1] = cost[0][1], dp[0][2] = cost[0][2];
	
	for (int i = 1; i < n; i++) {
		//i번째 집 색깔 별로 최소 비용 구하기
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++) { //0:red, 1: green, 2:blue
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	//출력
	cout << minCost(n, cost) << '\n';
}