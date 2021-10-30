#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//용액 하나는 고정 후 다른 두 용액 이용해 0에 가깝게 혼합
vector<int> liquid(vector<int> arr, int num, int idx) {
	vector<int> ans(3, 0);
	long long min_diff = 3 * 1e9 + 1;

	int left = idx + 1, right = arr.size() - 1;
	ans[0] = num;

	while (left < right) {
		long long mix = (long long) num +  arr[left] + arr[right]; //세 용액 혼합
		if (mix == 0) { // 혼합된 값이 0이라면 바로 반환
			ans[1] = arr[left], ans[2] = arr[right];
			return ans;
		}
		if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
			min_diff = abs(mix);
			ans[1] = arr[left], ans[2] = arr[right];
		}

		if (mix > 0)// 0보다 크면 right 포인터 왼쪽으로 이동
			right--;
		else if (mix < 0) // 0보다 작으면 left 포인터 오른쪽으로 이동
			left++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	//입력
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//정렬
	sort(arr.begin(), arr.end());

	//연산
	vector<int> temp;
	vector<int> ans;
	long long sum_ans = 3 * 1e9 + 1, sum_temp = 0;

	for (int i = 0; i < n - 2; i++) {
		//arr[i]: 고정할 용액
		temp = liquid(arr, arr[i], i);

		for (int i = 0; i < 3; i++)
			sum_temp +=  temp[i]; //세 용액의 특성값의 합

		if (abs(sum_temp) < abs(sum_ans)) { //이전에 구한 합보다 0에 가깝다면 정답 갱신
			ans = temp;
			sum_ans = sum_temp;
		}
		sum_temp = 0;
	}
	sort(ans.begin(), ans.end()); //답 정렬

	//출력
	for (int i = 0; i < 3; i++)
		cout << ans[i] << ' ';
}