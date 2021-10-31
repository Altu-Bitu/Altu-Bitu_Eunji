#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//좋은 수인지 아닌지 반환하는 함수
bool isGood(int idx, int num, vector<int>numbers) {
	int left = 0, right = numbers.size() - 1;

	while (left < right) {
		if (left == idx) { //왼쪽 포인터가 num의 인덱스와 같다면
			left++;
			continue;
		}
		if (right == idx) { //오른쪽 포인터가 num의 인덱스와 같다면
			right--;
			continue;
		}

		int sum = numbers[left] + numbers[right];

		if (sum == num) //left, right가 가리키는 숫자의 합이 num이 된다면 true 반환
			return true;
		else if (sum < num)  //합이 num보다 작다면 left 포인터 오른쪽으로 이동
			left++;
		else //합이 num보다 크다면 right 포인터 왼쪽으로 이동
			right--;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	//입력
	cin >> n;
	vector<int>numbers(n, 0);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	//정렬
	sort(numbers.begin(), numbers.end());

	//연산 및 출력
	int ans = 0;
	if (n >= 3) {
		for (int i = 0; i < n; i++) {
			if (isGood(i, numbers[i], numbers))
				ans++;
		}
	}
	cout << ans << '\n';	
}