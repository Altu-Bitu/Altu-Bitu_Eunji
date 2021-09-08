#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, main_supervisor, sub_supervisor; //시험장 수, 총감독관 수, 부감독관 수
	long long total = 0; //필요한 감독관의 수
	vector<int> number; //시험장 별 응시자 수

	//입력
	cin >> n;
	number.assign(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> number[i];
	cin >> main_supervisor >> sub_supervisor;
	
	total += n; //총감독관은 무조건 들어가므로
	for (int i = 0; i < n; i++) {
		if (number[i] > main_supervisor)
			total += (number[i] - main_supervisor - 1) / sub_supervisor + 1;
	}

	cout << total;


}