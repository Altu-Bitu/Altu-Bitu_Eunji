#include<iostream>
#include<vector>

using namespace std;

vector<int> result;

void add(string a, string b) {
	int size_a = a.size(), size_b = b.size();
	int carry = 0;
	
	while (size_a || size_b) {
		//각 자릿수에 해당하는 수 및 그 합을 저장할 변수
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

	//입력
	cin >> a >> b;

	//계산
	add(a, b);

	//출력
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
}