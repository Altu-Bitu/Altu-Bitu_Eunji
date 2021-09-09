#include<iostream>
#include<vector>
#include<algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> i1, pair<int, int> i2) {
	if (i1.second == i2.second)
		return i1.first < i2.first;
	else 
		return i1.second < i2.second;
}


int main() {
	int n; //좌표 개수
	vector<pair<int, int>> points;

	//입력
	cin >> n;
	points.assign(n, {});
	for (int i =0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

	//정렬
	sort(points.begin(), points.end(), compare);

	//결과 출력
	for (int i = 0; i < n; i++) {
		cout << points[i].first << ' ' << points[i].second << "\n";
	}
}