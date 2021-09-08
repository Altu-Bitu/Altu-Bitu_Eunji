#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int min_time = 0;

	//입력
	cin >> n;
	vector<int>time;
	time.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	//정렬
	sort(time.begin(), time.end());

	//최소 시간 계산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			min_time += time[j];
		}
	}

	//출력
	cout << min_time;
	
}