#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int minTime(int n, vector<int> time) {	
	sort(time.begin(), time.end());
	int min_time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			min_time += time[j];
		}
	}
	return min_time;
}

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

	
	//출력
	min_time = minTime(n, time);
	cout << min_time;
	
}