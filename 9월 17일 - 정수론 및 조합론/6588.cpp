#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//최대 크기까지 미리 소수 판별하기 위한 배열
const int SIZE = 1000001;
vector<bool>prime(SIZE, true); 

//소수 판별 함수
void isPrime(vector<bool> &prime) {
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i]) {
			for (int j = i * i; j < SIZE; j += i)
				prime[j] = false;
		}
	}
}

//덧셈 결과가 n인 두 홀수인 소수 구하는 함수
vector<int> goldbach(int n) {
	vector<int>result(2, 0);

	for (int i = 3; i <= n/2; i++) {
		if (prime[i] && prime[n - i]) {
				result[1] = n - i;
				result[0] = i;
				//작은 수부터 시작해서 i를 증가시키므로 제일 처음 조건에 맞는 i와 n-i의 차가 가장 큼
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

	//미리 소수 판별
	isPrime(prime);

	//입력 및 출력
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