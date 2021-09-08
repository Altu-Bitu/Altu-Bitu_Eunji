#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string i1, string i2) {
	if (i1.length() != i2.length())
		return i1.length() < i2.length();
	
	// 시리얼 번호의 합 구하기
	int i1_sum = 0, i2_sum = 0;

	for (int i = 0; i < i1.length(); i++) {
		if (i1[i] - '0' <= 9 && i1[i] - '0' >= 0)
			i1_sum += i1[i] - '0';
	}
	for (int i = 0; i < i2.length(); i++) {
		if (i2[i] - '0' <= 9 && i2[i] - '0' >= 0)
			i2_sum += i2[i] - '0';
	}

	if (i1_sum != i2_sum)
		return i1_sum < i2_sum;

	return i1 < i2;
}

int main() {
	int n;
	vector<string>serial_number;

	//입력
	cin >> n;
	serial_number.assign(n,"");
	for (int i = 0; i < n; i++) {
		cin >> serial_number[i];
	}

	//정렬
	sort(serial_number.begin(), serial_number.end(), compare);

	//출력
	for (int i = 0; i < n; i++) {
		cout << serial_number[i] << "\n";
	}
}