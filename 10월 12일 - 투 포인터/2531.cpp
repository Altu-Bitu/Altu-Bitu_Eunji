#include <iostream>
#include <vector>
#include <map>

using namespace std;

//초밥 가짓수의 최댓값 출력하는 함수
int maxCount(int k, int n, int c, vector<int>plates) {
	int ans = 0; //가짓수의 최댓값
	map<int, int> type; //초밥 종류 당 개수 저장
	type[c] = 1; //초기화(쿠폰 번호에 해당하는 초밥은 카운트하지 않도록)
	int temp = 0; //left ~ right 범위에서 초밥의 가짓수

	for (int i = 0; i < k; i++) {
		type[plates[i]]++;
		if (type[plates[i]] == 1)
			temp++; //종류 증가
	}
	ans = temp;

	int left = 0, right = k; //k개의 범위에서 제거할 원소 가리키는 포인터(left), 범위에 추가할 원소 가리키는 포인터(right)
	while (left < n - 1) {
		type[plates[left]]--; //제일 앞 쪽 초밥 종류 하나 제거
		if (type[plates[left]] == 0) { //제거한 초밥 종류가 k개 범위에 없다면
			temp--; //종류 감소
			type.erase(plates[left]);
		}

		type[plates[right]]++; //해당 종류에 해당하는 초밥의 개수 증가
		if (type[plates[right]] == 1) // k개의 범위 내에 없던 종류라면
			temp++; //종류 증가
		ans = max(ans, temp); //최댓값 갱신

		left++; //left, right 포인터 하나씩 증가
		right = (right + 1) % n;
	}
	return ans + 1; //쿠폰으로 받는 초밥 종류 하나 더해서 반환
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c;

	//입력
	cin >> n >> d >> k >> c;
	vector<int>plates(n);

	for (int i = 0; i < n; i++)
		cin >> plates[i];

	//연산 및 출력
	cout << maxCount(k, n, c, plates) << '\n';
}