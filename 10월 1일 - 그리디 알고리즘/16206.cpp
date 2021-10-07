#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m; //자를 수 있는 횟수

//비교 함수
bool compare(const int& a, const int& b) {
	//10의 배수이면 오름차순
	if (a % 10 == 0 && b % 10 == 0)
		return a < b;

	//10의 배수가 앞쪽으로 가도록
	return (a % 10 == 0 && b % 10 != 0);
}

//자르는 함수
int cutting(int a) {
	int cnt = 0; //길이 10인 케이크의 개수

	if (a % 10 == 0) { //10의 배수인 경우
		if (a / 10 - 1 > m) { //자를 수 있는 횟수 이내에 케이크를 모두 10으로 분할할 수 없는 경우
			cnt = m;
			m = 0;
		}
		else {
			cnt += a / 10;
			m = m - a / 10 + 1;
		}	
	}
	else { //10의 배수가 아닌 경우
		if (a / 10 > m) {
			cnt = m;
			m = 0;
		}
		else {
			cnt += a / 10;
			m = m - a / 10;
		}
	}
	
	
	return cnt;
}

//케이크 개수 최댓값 구하는 함수
int maxCakeCount(vector<int>a) {
	int cnt = 0;
	int size = a.size();
	int idx = 0;

	while (m > 0 && idx < size) {//자를 수 있고, 가지고 있는 케이크 개수를 넘어가지 않는 한 반복
		if (a[idx] == 10) //길이가 10이면 자를 필요 없음
			cnt++;
		else 
			cnt += cutting(a[idx]); //자르기

		idx++;
	}

	return cnt;
}

int main() {
	int n;

	//입력
	cin >> n >> m;
	vector<int>a;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input < 10) //10보다 작으면
			continue;
		a.push_back(input);
	}

	//정렬
	sort(a.begin(), a.end(), compare);


	//연산 + 출력
	cout << maxCakeCount(a) << '\n';
}