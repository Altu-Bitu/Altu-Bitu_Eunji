#include<iostream>
#include<vector>

using namespace std;

vector<int> result;

void add(string a, string b) {
	int size_a = a.size(), size_b = b.size();
	int carry = 0;
	
	while (size_a || size_b) {
		//�� �ڸ����� �ش��ϴ� �� �� �� ���� ������ ����
		int a_temp, b_temp, sum_temp;

		a_temp = 0;
		b_temp = 0;
		sum_temp = 0;

		if (size_a > 0) {
			a_temp = a[size_a - 1] - '0';
			size_a--;
		}
		
		if (size_b > 0) {
			b_temp = b[size_b - 1] - '0';
			size_b--;
		}


		sum_temp = a_temp + b_temp + carry;

		if (sum_temp > 9) {
			result.push_back(sum_temp % 10);
			carry = 1;
		}
		else {
			result.push_back(sum_temp);
			carry = 0;
		}
		
	}
	if (carry) result.push_back(1);
}

int main() {
	string a, b;

	//�Է�
	cin >> a >> b;

	//���
	add(a, b);

	//���
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
}