#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input1, input2;

	//입력
	cin >> input1 >> input2; //최대공약수, 최소공배수
	vector<int> result(2, input2);

	//연산 및 출력
	int temp = input2 / input1;
	//곱해서 temp(최소공배수를 최대공약수로 나눈 값)가 되는 두 수, 즉 tempe 약수 중 서로소인 것을 찾아야 한다.
	//그렇지 않으면 입력받은 최대공약수보다 더 큰 최대공약수를 가진다.
	for (int i = sqrt(temp); i >= 1; i--) {
		if (temp % i == 0) {
			if (gcdRecursion(temp / i, i) == 1 && result[0] + result[1] > i + temp / i) {
				result[0] = i;
				result[1] = temp / i;
				break;
			}	
		}
	}

	for (int i = 0; i < 2; i++) {
		result[i] *= input1; //입력받은 수가 최대공약수가 되도록 앞에서 찾은 두 값에 최대공약수를 곱함.
		cout << result[i] << ' ';
	}
}