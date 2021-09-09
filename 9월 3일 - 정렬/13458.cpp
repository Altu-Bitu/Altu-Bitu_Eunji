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
	int n, main_supervisor, sub_supervisor; //������ ��, �Ѱ����� ��, �ΰ����� ��
	long long total = 0; //�ʿ��� �������� ��
	vector<int> number; //������ �� ������ ��

	//�Է�
	cin >> n;
	number.assign(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> number[i];
	cin >> main_supervisor >> sub_supervisor;

	//���
	total = numOfSuperivsor(n, number, main_supervisor, sub_supervisor);
	cout << total;


}