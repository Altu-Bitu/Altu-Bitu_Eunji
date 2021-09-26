#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 45;

bool eureka(int num, vector<int> triangular_num) {
	int n = SIZE - 1;
	
	//입력 받은 수(num)보다 작은 삼각수가 몇번째인지 구해서 n에 저장
	for (int i = 1; i < SIZE; i++) {
		if (triangular_num[i] > num) {
			n = i;
			break;
		}
	}

	//삼각수 3개의 합으로 표현되는지 검사
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				if (triangular_num[i] + triangular_num[j] + triangular_num[k] == num)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	vector<bool> result(n, false);
	vector<int> triangular_num(SIZE, 0);

	//미리 삼각수 구해서 배열에 저장
	for (int i = 1; i < SIZE; i++) {
		triangular_num[i] = i * (i + 1) / 2;
	}

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		result[i] = eureka(input, triangular_num);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << '\n';
}