#include <iostream>
#include <vector>
#include <map>

using namespace std;

//최장 연속 수열의 길이 구하는 함수
int maxLength(int n, int k, vector<int> numbers) {
	int ans = 1; //최장 길이 저장할 변수
	int left = 0, right = 0;
	map<int, int> count; //원소가 나온 횟수 저장하는 벡터
	count[numbers[left]]++; //초기화
	int temp = 1; //현재까지 수열의 길이 저장
	while (left <= right && right < n - 1) {
		if (count[numbers[right]] <= k) { //원소의 횟수가 k 이하인 경우
			right++; //오른쪽 포인터 증가하며 범위 증가
			count[numbers[right]]++; //증가한 오른쪽 포인터가 가리키는 원소의 횟수 증가
			temp++; //수열의 길이 증가
			if (count[numbers[right]] <= k)
				ans = max(ans, temp); //최장 길이 갱신
		}
		else { //원소의 횟수가 k를 초과한 경우
			count[numbers[left]]--; //왼쪽 포인터가 가리키는 원소의 횟수 감소 후
			left++; //왼쪽 포인터 감소
			temp--; //수열의 길이 감소
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	//입력
	cin >> n >> k;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	//연산 및 출력
	cout << maxLength(n, k, numbers) << '\n';
}