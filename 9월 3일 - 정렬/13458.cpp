#include<iostream>
#include<vector>

using namespace std;

long long numOfSuperivsor(int n, vector<int> number, int main_supervisor, int sub_supervisor) {
	long long total = 0;

	total += n;
	for (int i = 0; i < n; i++) {
		if (number[i] > main_supervisor)
			total += (number[i] - main_supervisor - 1) / sub_supervisor + 1;
	}

	return total;
}

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

	//출력
	total = numOfSuperivsor(n, number, main_supervisor, sub_supervisor);
	cout << total;


}