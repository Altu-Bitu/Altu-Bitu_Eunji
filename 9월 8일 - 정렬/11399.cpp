#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int min_time = 0;

	//�Է�
	cin >> n;
	vector<int>time;
	time.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	//����
	sort(time.begin(), time.end());

	//�ּ� �ð� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			min_time += time[j];
		}
	}

	//���
	cout << min_time;
	
}