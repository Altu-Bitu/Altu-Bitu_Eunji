#include <iostream>
#include <vector>

using namespace std;

void maxPay(int start, int pay, int & result, vector<pair<int, int>> time_and_pay) {
	//퇴사일이 되면
	if (start == time_and_pay.size()) {
		//모든 경우의 pay 중 가장 큰 pay가 result에 저장됨
		result = max(result, pay);
		return;
	}
	//start일에 일을 하는 경우
	//일이 끝나는 시점이 퇴사일을 넘어가면 안 됨
	if (start + time_and_pay[start].first <= time_and_pay.size())
		maxPay(start + time_and_pay[start].first, pay + time_and_pay[start].second, result, time_and_pay);
	//start일에 일을 하지 않는 경우
	if(start + 1 <= time_and_pay.size())
		maxPay(start + 1, pay, result, time_and_pay);
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<pair<int, int>> time_and_pay(n, {0, 0});

	for (int i = 0; i < n; i++) {
		cin >> time_and_pay[i].first >> time_and_pay[i].second;
	}

	//연산
	int max_pay = 0 ;
	maxPay(0, 0, max_pay, time_and_pay);

	//출력
	cout << max_pay << '\n';
}