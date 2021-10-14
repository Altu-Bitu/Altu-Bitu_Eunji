#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> snack;

//���� ���̰� length�� �� ������ ���� ������ ��
int snacks(int length) {
	int cnt = 0;

	for (int i = 0; i < snack.size(); i++) {
		if (snack[i] >= length)
			cnt += snack[i] / length;
	}
	
	return cnt;
}

//���� ������ �ִ� ����
int upperLength(int left, int right, int target) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = snacks(mid); //���̰� mid �� �� ���ڰ� �� ����?

		if (num < target) //������ ������ ��ī�� ������ ������ ������ ���̸� �ٿ��� ������ �÷��� ��
			right = mid - 1;
		if (num >= target) { //������ ������ ��ī�鿡�� ������ �� �ִ� ��� ������ ���̸� �÷��� �� ����
			ans = mid;
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, m;

	//�Է�
	cin >> m >> n;
	snack.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> snack[i];

	//����
	sort(snack.begin(), snack.end());
	
	//����
	int start; // ������ �ּ� ����
	if (snack[0] / m > 0)
		start = snack[0] / m;
	else
		start = 1;
	cout << upperLength(start, snack[n - 1], m) << '\n';
}