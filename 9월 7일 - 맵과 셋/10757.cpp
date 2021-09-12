#include<iostream>
#include<vector>

using namespace std;

vector<int> result;

void add(vector<int> &a, vector<int> &b) {
	int idx = 0;
	int size_a = a.size(), size_b = b.size();
	bool carry = 0;
	
	while (size_a || size_b) {
		//각 자릿수에 해당하는 수 및 그 합을 저장할 변수
		int a_temp, b_temp, sum_temp;

		a_temp = 0;
		b_temp = 0;

		if (size_a > 0) {
			a_temp = a[idx];
			size_a--;
		}
		if (size_b > 0) {
			b_temp = b[idx];
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
		
		idx++;
	}
	if (carry) result.push_back(1);
}

int main() {
	vector<int> a;
	vector<int> b;
	string input;;

	//입력
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		a.push_back(input[input.length() - 1 - i] - '0');
	}
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		b.push_back(input[input.length() - 1 - i] - '0');
	}

	//계산
	add(a, b);

	//출력
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
}