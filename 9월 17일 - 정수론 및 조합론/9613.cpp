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
	
	//�Է�
	cin >> t;

	//���̽��� �Է� �� ���� �� ���
	while (t--) {
		cin >> n;

		//�ԷµǴ� ������ ������ ����
		vector<int> input(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		long long sum = 0;
		//�ݺ����� ���� ������ ��� ������ GCD�� �� ���ϱ�
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcdRecursion(max(input[i], input[j]), min(input[i], input[j]));
			}
		}

		//���
		cout << sum << '\n';
	}
}