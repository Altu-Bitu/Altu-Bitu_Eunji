#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, min = 0;
	vector<int> a;
	vector<int> b;

	//ют╥б
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < n; i++) {
		min += a[i] * b[i];
	}
	cout << min;
}