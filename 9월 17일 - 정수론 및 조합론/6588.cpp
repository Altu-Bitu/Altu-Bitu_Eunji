#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//�ִ� ũ����� �̸� �Ҽ� �Ǻ��ϱ� ���� �迭
const int SIZE = 1000001;
vector<bool>prime(SIZE, true); 

//�Ҽ� �Ǻ� �Լ�
void isPrime(vector<bool> &prime) {
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i]) {
			for (int j = i * i; j < SIZE; j += i)
				prime[j] = false;
		}
	}
}

//���� ����� n�� �� Ȧ���� �Ҽ� ���ϴ� �Լ�
vector<int> goldbach(int n) {
	vector<int>result(2, 0);

	for (int i = 3; i <= n/2; i++) {
		if (prime[i] && prime[n - i]) {
				result[1] = n - i;
				result[0] = i;
				//���� ������ �����ؼ� i�� ������Ű�Ƿ� ���� ó�� ���ǿ� �´� i�� n-i�� ���� ���� ŭ
				return result;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int>result(2, 0);

	//�̸� �Ҽ� �Ǻ�
	isPrime(prime);

	//�Է� �� ���
	cin >> n;
	while (n != 0) {
		result = goldbach(n);
		if (result[0] != 0)
			cout << n << " = " << result[0] << " + " << result[1] << '\n';
		else
			cout << "Goldbach's conjecture is wrong." << '\n';
		cin >> n;
	}
}