#include <iostream>

using namespace std;

int combination(int n, int k) {
	int a = 1, b = 1;

	while (k) {
		a *= n;
		b *= k;
		n--;
		k--;
	}
	return a / b;
}

int main() {
	int n, k, result;

	//입력
	cin >> n >> k;

	//연산
	result = combination(n, k);

	//출력
	cout << result << '\n';

}
