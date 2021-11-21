#include <iostream>
#include <vector>

using namespace std;

int countCase(vector<int>num, int length) {
	vector<int> dp(length + 1, 0); //dp �迭
	dp[0] = 1; //dp �迭 �ʱ�ȭ
	
	//ù��° ���ں��� ����
	for (int i = 1; i <= length; i++) {
		if (num[i] != 0) //�ش� ���ڰ� 0�� �ƴϸ� �� ��ü�� ���ĺ� �ϳ��� ��Ÿ�� �� ����.
			dp[i] = dp[i - 1]; //�� ��� �ؼ��� �������� �ٷ� ������ �������� ����.
		int temp = num[i] + num[i - 1] * 10;
		if (temp >= 10 && temp <= 26) //���� ���ڿ� ���ؼ� 10~26�̶�� ���ĺ��� ��Ī �����ϹǷ�
			dp[i] = (dp[i] + dp[i - 2]) % 1000000; //�� ���� �ι�° ���� �������� ����.
	}
	return dp[length];
}

int main() {
	string input;

	//�Է�
	cin >> input;
	int length = input.size();
	vector<int>num(length + 1, 0);
	for (int i = 1; i <= length; i++) {
		num[i] = input[i - 1] - '0';
	}

	//���� �� ���
	cout << countCase(num, length) << '\n';
}