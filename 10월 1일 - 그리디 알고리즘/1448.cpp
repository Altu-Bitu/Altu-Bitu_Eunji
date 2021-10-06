#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLengthSum(int n, vector<int>straw) {
	int ans = 0;

	for (int i = n - 1; i >= 2; i--) { //삼각형 만들기, 세 변의 길이의 합이 최대가 되어야 하므로 뒤쪽 인덱스부터 확인
		if (straw[i] < straw[i - 1] + straw[i - 2]) { // 삼각형이 만들어진다면
			ans = straw[i] + straw[i - 1] + straw[i - 2];
			return ans;
		}
	}

	return -1; //삼각형이 만들어지지 않으므로 -1 반환
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<int>straw(n, 0);

	for (int i = 0; i < n; i++)
		cin >> straw[i];

	//정렬
	sort(straw.begin(), straw.end());

	//연산 + 출력
	cout << maxLengthSum(n, straw) << '\n';
}