#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> snack;

//과자 길이가 length일 때 나오는 과자 조각의 수
int snacks(int length) {
	int cnt = 0;

	for (int i = 0; i < snack.size(); i++) {
		if (snack[i] >= length)
			cnt += snack[i] / length;
	}
	
	return cnt;
}

//막대 과자의 최대 길이
int upperLength(int left, int right, int target) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = snacks(mid); //길이가 mid 일 때 과자가 몇 조각?

		if (num < target) //과자의 개수가 조카의 수보다 적으면 과자의 길이를 줄여서 개수를 늘려야 함
			right = mid - 1;
		if (num >= target) { //과자의 개수를 조카들에게 나눠줄 수 있는 경우 과자의 길이를 늘려볼 수 있음
			ans = mid;
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, m;

	//입력
	cin >> m >> n;
	snack.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> snack[i];

	//정렬
	sort(snack.begin(), snack.end());
	
	//연산
	int start; // 과자의 최소 길이
	if (snack[0] / m > 0)
		start = snack[0] / m;
	else
		start = 1;
	cout << upperLength(start, snack[n - 1], m) << '\n';
}