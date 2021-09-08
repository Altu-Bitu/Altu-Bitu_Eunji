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
	int n; //��ǥ ����
	vector<pair<int, int>> points;

	//�Է�
	cin >> n;
	points.assign(n, {});
	for (int i =0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

	//����
	sort(points.begin(), points.end(), compare);

	//��� ���
	for (int i = 0; i < n; i++) {
		cout << points[i].first << ' ' << points[i].second << "\n";
	}
}