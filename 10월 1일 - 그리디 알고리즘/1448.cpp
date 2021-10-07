#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLengthSum(int n, vector<int>straw) {
	int ans = 0;

	for (int i = 0; i < n-2; i++) { //�ﰢ�� �����
		if (straw[i] < straw[i + 1] + straw[i + 2]) { // �ﰢ���� ��������ٸ�
			ans = straw[i] + straw[i + 1] + straw[i + 2];
			return ans;
		}
	}

	return -1; //�ﰢ���� ��������� �����Ƿ� -1 ��ȯ
}

int main() {
	int n;

	//�Է�
	cin >> n;
	vector<int>straw(n, 0);

	for (int i = 0; i < n; i++)
		cin >> straw[i];

	//����(��������)
	sort(straw.begin(), straw.end(),greater<>());

	//���� + ���
	cout << maxLengthSum(n, straw) << '\n';
}