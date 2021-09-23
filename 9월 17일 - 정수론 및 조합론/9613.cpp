#include <iostream>
#include <vector>
using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0)
		return a;
	return gcdRecursion(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	
	//입력
	cin >> t;

	//케이스별 입력 후 연산 및 출력
	while (t--) {
		cin >> n;

		//입력되는 수들을 저장할 벡터
		vector<int> input(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		long long sum = 0;
		//반복문을 통해 가능한 모든 조합의 GCD의 합 구하기
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcdRecursion(max(input[i], input[j]), min(input[i], input[j]));
			}
		}

		//출력
		cout << sum << '\n';
	}
}