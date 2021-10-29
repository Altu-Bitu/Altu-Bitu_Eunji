#include <iostream>
#include <vector>
#include <map>

using namespace std;

//초밥 가짓수의 최댓값 출력하는 함수
int maxCount(int k, int n, int c, vector<int>plates) {
	int ans = 0; //정답

	int left = 0, right = 0;
	map<int, int> type; //초밥 종류 당 개수 저장
	type[plates[left]]++; //초기화
	int temp = 1; //left ~ right 범위에서 초밥의 가짓수

	while (left < n) {
		right++; //범위 늘림
		if (right == n) // right가 접시 수를 넘어가면 처음 접시를 가리키도록
			right = 0;
		type[plates[right]]++; //해당 종류에 해당하는 초밥의 개수 증가
		if (type[plates[right]] == 1 && plates[right] != c) // left ~ right 범위 내에 없던 종류이고 쿠폰에 적힌 초밥이 아니라면
			temp++; //종류 증가


		// left ~ right 범위 사이의 접시 개수가 k개이면
		if ((right > left && right - left == k - 1) || (right < left && left - right == n - k + 1)) {
			ans = max(temp, ans); //ans 갱신
			//left 값 증가 전 처리
			type[plates[left]]--;
			if (type[plates[left]] == 0) {
				type.erase(plates[left]);
				if (plates[left] != c)
					temp--;
			}
			left++; //left 증가
		}
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