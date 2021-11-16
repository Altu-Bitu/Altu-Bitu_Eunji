#include <iostream>
#include <vector>

using namespace std;

//������
vector<int> back(int x, vector<int>& path) {
	vector<int>result(0);
	while (x != -1) {
		result.push_back(x);
		x = path[x];
	}
	return result;
}

int minCount(int n, vector<int> &path) {
	vector<int>dp(n + 1, 0); //dp �迭

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1; //�켱 1�� ���� ���� ����
		path[i] = i - 1;
	
		if (i % 2 == 0 && dp[i / 2] < dp[i] - 1) { //2�� ������ �������� 1�� ���� �ͺ��� ���� Ƚ���� ���ٸ�
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i / 3] < dp[i] - 1) { //3���� ������ �������� 1�� ���� ��(+ 2�� ������ ��)���� ���� Ƚ���� ���ٸ�
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
		}
	}
	return dp[n];
}

int main() {
	int n;
	
	//�Է�
	cin >> n;
	vector<int>path(n + 1, -1); //��� ������ �迭

	//����
	int ans = minCount(n, path);
	vector<int>result = back(n, path);
	
	//���
	cout << ans << '\n';
	for (int i = 0; i <result.size(); i++)
		cout << result[i] << ' ';
}