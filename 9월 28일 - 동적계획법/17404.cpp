#include <iostream>
#include <vector>

using namespace std;


int minCost(int n, vector<vector<int>>cost) {
	int ans = 1000001;

	//dp[i][0~2]: i번째 집을 각각 red, green, blue로 지었을 때의 최소 비용
	vector<vector<int>> dp(n, vector<int>(3, 1000001));


	//처음에 칠한 색을 정하고 color 인덱스에 저장
	for (int color = 0; color < 3; color++) {

		//0번째 집
		//다음 집의 색을 정할 때 이전 집의 색으로 현재 색을 선택해야 하므로 
		//현재 색에 대한 비용만 dp[0]에 업데이트, 나머지는 최댓값(1000001)가짐
		dp[0][color] = cost[0][color];

		for (int i = 1; i < n; i++) {
			//i번째 집 색깔 별로 최소 비용 구하기
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++) {
			if (i == color) continue; //마지막 집과 첫번째 집의 색이 같으면 안 되므로
			ans = min(ans, dp[n - 1][i]);
		}

		//재설정
		dp[0][color] = 1000001;
	}
	return ans;
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