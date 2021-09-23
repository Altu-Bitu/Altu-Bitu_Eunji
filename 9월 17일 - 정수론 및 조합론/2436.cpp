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

	//�Է�
	cin >> input1 >> input2; //�ִ�����, �ּҰ����
	vector<int> result(2, input2);

	//���� �� ���
	int temp = input2 / input1;
	//���ؼ� temp(�ּҰ������ �ִ������� ���� ��)�� �Ǵ� �� ��, �� tempe ��� �� ���μ��� ���� ã�ƾ� �Ѵ�.
	//�׷��� ������ �Է¹��� �ִ��������� �� ū �ִ������� ������.
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
		result[i] *= input1; //�Է¹��� ���� �ִ������� �ǵ��� �տ��� ã�� �� ���� �ִ������� ����.
		cout << result[i] << ' ';
	}
}