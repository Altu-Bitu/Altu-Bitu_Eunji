//참고 블로그: https://far-simple.tistory.com/38
#include <iostream>
#include <vector>

using namespace std;

//dp 배열 이용해 최장 부분 수열 구하는 함수
string back(string input1, int size1, int size2, int max_length, vector<vector<int>> &dp) {
	string ans = ""; //부분 수열
	int idx1 = size1, idx2 = size2; //dp 배열에 사용할 인덱스, 현재 위치(오른쪽 아래에서 시작)
	int length = max_length; //부분 수열의 길이

	//부분 수열이 완성되지 않으면 반복
	while (length > 0) {
		if (dp[idx1][idx2] == dp[idx1][idx2 - 1]) //만약 현재 인덱스에서의 dp 값이 왼쪽의 dp 값과 같다면 왼쪽에서 온 값
			idx2--; //왼쪽으로 이동
		else if (dp[idx1][idx2] == dp[idx1 - 1][idx2]) //만약 현재 인덱스에서의 dp 값이 위쪽의 dp 값과 같다면 위에서 온 값
			idx1--; //현재 위치를 위쪽으로 이동
		else { //만약 현재 인덱스에서의 dp 값이 왼쪽 위에서 온 값이라면
			ans = input1[--idx1] + ans; //부분 수열 갱신
			idx2--; //현재 위치 갱신(왼쪽 위로)
			length--; //앞으로 채워야할 길이 하나 감소
		}
	}
	return ans;
}

//가장 긴 부분 수열의 길이 구하는 함수
int lcs(string input1, string input2, vector<vector<int>> &dp) {
	int size1 = input1.size(); //문자열 1의 길이
	int size2 = input2.size(); //문자열 2의 길이

	for (int i = 1; i <= size1; i++) { //dp 배열은 행, 열의 인덱스 1부터 시작
		for (int j = 1; j <= size2; j++) {
			if (input1[i - 1] == input2[j - 1]) //문자가 서로 같으면
				dp[i][j] = dp[i - 1][j - 1] + 1; //왼쪽 위의 값(해당 문자가 포함되기 전 위치) + 1
			else //문자가 다르다면
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //왼쪽 혹은 위쪽에서 더 큰 값을 가져온다.
		}
	}

	return dp[size1][size2];
}

int main() {
	string input1, input2;

	//입력
	cin >> input1 >> input2;

	int size1 = input1.size();
	int size2 = input2.size();
	vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0)); //dp 배열
	
	//연산 및 출력
	int max_length = lcs(input1, input2, dp);
	cout << max_length << '\n';
	
	if (max_length != 0)  //부분 수열의 길이가 0이 아니라면 부분 수열 출력
		cout << back(input1, size1, size2, max_length, dp) << '\n';
}