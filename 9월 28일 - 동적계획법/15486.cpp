#include <iostream>
#include <vector>

using namespace std;

int maxPay(int n, vector<pair<int,int>> pay_info) {
	int ans = 0;
	
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		//일을 하지 않는 경우
		if (i < n) //다음 날에 현재 pay 저장
			dp[i + 1] = max(dp[i + 1], dp[i]);

		//일을 하는 경우
		if (i + pay_info[i].first <= n ) { //일이 끝나는 시점이 퇴사일을 넘어가지 않으면
			dp[i] += pay_info[i].second; //pay 업데이트
			dp[i + pay_info[i].first] = max(dp[i + pay_info[i].first], dp[i]); //일을 완료한 날 pay 업데이트
		}
		if (i + pay_info[i].first == n+1) //일이 끝나는 시점이 딱 퇴사일이면
			dp[i] += pay_info[i].second; //일을 완료한 날의 pay는 업데이트할 필요 없음

		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<pair<int, int>> pay_info(n + 1, { 0,0 });
	for (int i = 1; i <= n; i++) {
		cin >> pay_info[i].first >> pay_info[i].second;
	}

	//출력
	cout << maxPay(n, pay_info) << '\n';
}