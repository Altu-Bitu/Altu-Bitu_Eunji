#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

//구간의 점수의 최댓값이 최솟값이 mid 일 때 구간의 개수
int countSection(int mid) {
	int cnt = 1; //구간의 개수는 1개 이상이므로
	int min_score = arr[0], max_score = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		min_score = min(min_score, arr[i]);
		max_score = max(max_score, arr[i]);

		if (max_score - min_score > mid) {
			cnt++;
			min_score = arr[i];
			max_score = arr[i];
		}
	}
	return cnt;
}

//구간의 점수의 최댓값의 최솟값을 구하는 함수
int minOfMaxSectionScore(int left, int right, int m) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = countSection(mid); //구간의 개수
		if (cnt <= m) { //구간의 개수가 m 이하라면 최댓값의 최솟값을 더 줄여본다
			ans = mid;
			right = mid - 1;
		}
		else if (cnt > m) {//구간의 개수가 m을 초과하면 최댓값의 최솟값을 더 늘려야 한다.
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	//입력
	cin >> n >> m;
	arr.assign(n, 0);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(arr[i], right);
	}

	//연산 및 출력
	cout << minOfMaxSectionScore(0, right, m) << '\n';
}