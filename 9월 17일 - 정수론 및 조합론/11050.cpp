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

	//�Է�
	cin >> n >> k;

	//����
	result = combination(n, k);

	//���
	cout << result << '\n';

}
