#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//자르는 함수
void cutting(vector<int> &a, int &idx, int &cnt, int &m) {
	while (a[idx] > 10) { //케이크가 10보다 크다면
		a[idx] -= 10; // 10 만큼 자르기
		cnt++; // 길이가 10인 케이크가 생겼으므로 증가
		m--; //자를 수 있는 횟수는 감소
		if (m == 0) //자를 수 없게 되면
			break;
	}

	//다 자르고 난 결과
	if (a[idx] == 10) { //10이면
		cnt++; //케이크 개수 증가
		idx++; //인덱스 증가
	}
	else { //10보다 작으면
		idx++; //인덱스만 증가
	}
}

//케이크 개수 최댓값 구하는 함수
int maxCakeCount(int m, vector<int>a, vector<int>multiple_of_10) {
	int cnt = 0;
	int size1 = multiple_of_10.size(), size2 = a.size();
	int idx1 = 0, idx2 = 0; //각각 multiple_of_10, a 배열 인덱스

	while (m > 0 && idx1 < size1) {//자를 수 있고, 가지고 있는 케이크 개수를 넘어가지 않는 한 반복
		cutting(multiple_of_10, idx1, cnt, m); //자르기
	}

	while (m > 0 && idx2 < size2) { //자를 수 있고, 가지고 있는 케이크 개수를 넘어가지 않는 한 반복
		cutting(a, idx2, cnt, m);
	}

	return cnt;
}

int main() {
	int n, m;

	//입력
	cin >> n >> m;
	vector<int>a;
	vector<int>multiple_of_10;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input < 10) //10보다 작으면
			continue;

		if (input % 10 == 0) //10으로 나누어 떨어진다면
			multiple_of_10.push_back(input);
		else
			a.push_back(input);
	}

	//정렬
	sort(a.begin(), a.end());
	sort(multiple_of_10.begin(), multiple_of_10.end());

	//연산 + 출력
	cout << maxCakeCount(m, a, multiple_of_10) << '\n';

}