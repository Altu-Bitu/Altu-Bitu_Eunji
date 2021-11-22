#include <iostream>
#include <vector>

using namespace std;

int countCase(string num, int length) {
	vector<int> dp(length + 1, 0); //dp 배열
	dp[0] = 1; //dp 배열 초기화
	((num[0] - '0') != 0) ? dp[1] = 1 : dp[1] = 0;
	
	//두번째 글자부터 시작
	for (int i = 1; i < length; i++) {
		if ((num[i] - '0') != 0) //해당 글자가 0이 아니면 그 자체가 알파벳 하나를 나타낼 수 있음.
			dp[i + 1] = dp[i]; //이 경우 해석의 가짓수는 바로 직전의 가짓수와 같다.
		int temp = (num[i] -'0') + (num[i - 1] - '0') * 10;
		if (temp >= 10 && temp <= 26) //이전 글자와 합해서 10~26이라면 알파벳과 매칭 가능하므로
			dp[i + 1] = (dp[i + 1] + dp[i - 1]) % 1000000; //이 경우는 두번째 전의 가짓수와 같다.
	}
	return dp[length];
}

int main() {
	string input;

	//입력
	cin >> input;
	int length = input.size();

	//연산 및 출력
	cout << countCase(input, length) << '\n';
}