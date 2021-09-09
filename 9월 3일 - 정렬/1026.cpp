#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minS(vector<int> &a, vector<int> &b) {
	int min = 0;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < a.size(); i++) {
		min += a[i] * b[i];
	}

	return min;
}

int main() {
	int n, min;
	vector<int> a;
	vector<int> b;

	//입력
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	min = minS(a, b);

	//출력
	cout << min;
}