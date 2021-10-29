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
		right++; //범위 늘림
		count[numbers[right]]++; //오른쪽 포인터가 가리키는 원소의 횟수 하나 늘림
		temp++; //현재 수열의 길이 1 증가

		if (count[numbers[right]] > k) { //만약 오른쪽 포인터가 가리키는 원소의 횟수가 k보다 크다면
			count[numbers[right]]--; //현재 오른쪽 포인터가 가리키고 있는 원소(오른쪽 포인터와 중복)의 횟수 하나 감소
			while (left <= right) { //왼쪽 포인터가 오른쪽 포인터보다 작을 때까지 범위 감소
				if (numbers[left] == numbers[right]) { //오른쪽 포인터가 가리키는 원소와 왼쪽 포인터가 가리키는 원소가 같으면
					left++; //왼쪽 포인터 증가 및
					temp--; //길이 감소 후
					break; // 반복문 탈출
				}

				//오른쪽 포인터와 왼쪽 포인터가 가리키는 원소가 다르다면
				count[numbers[left]]--; //원소가 나온 횟수 갱신
				left++; //왼쪽 포인터 증가
				temp--; //현재 수열의 길이 감소
			}
		}
		ans = max(ans, temp); //최장 길이 갱신
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