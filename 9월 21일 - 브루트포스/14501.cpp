#include <iostream>
#include <vector>

using namespace std;

void maxPay(int start, int pay, int & result, vector<int>T, vector<int>P) {
	//퇴사일이 되면
	if (start == T.size()) {
		//모든 경우의 pay 중 가장 큰 pay가 result에 저장됨
		result = max(result, pay);
		return;
	}
	//start일에 일을 하는 경우
	//일이 끝나는 시점이 퇴사일을 넘어가면 안 됨
	if (start + T[start] <= T.size())
		maxPay(start + T[start], pay + P[start], result, T, P);
	//start일에 일을 하지 않는 경우
	if(start + 1 <= T.size())
		maxPay(start + 1, pay, result, T, P);
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<int> T(n, 0);
	vector<int> P(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}

	//연산
	int max_pay = 0 ;
	maxPay(0, 0, max_pay, T, P);

	//출력
	cout << max_pay << '\n';
}