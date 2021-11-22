#include <iostream>
#include <vector>

using namespace std;

int countCase(string num, int length) {
	vector<int> dp(length + 1, 0); //dp �迭
	dp[0] = 1; //dp �迭 �ʱ�ȭ
	((num[0] - '0') != 0) ? dp[1] = 1 : dp[1] = 0;
	
	//�ι�° ���ں��� ����
	for (int i = 1; i < length; i++) {
		if ((num[i] - '0') != 0) //�ش� ���ڰ� 0�� �ƴϸ� �� ��ü�� ���ĺ� �ϳ��� ��Ÿ�� �� ����.
			dp[i + 1] = dp[i]; //�� ��� �ؼ��� �������� �ٷ� ������ �������� ����.
		int temp = (num[i] -'0') + (num[i - 1] - '0') * 10;
		if (temp >= 10 && temp <= 26) //���� ���ڿ� ���ؼ� 10~26�̶�� ���ĺ��� ��Ī �����ϹǷ�
			dp[i + 1] = (dp[i + 1] + dp[i - 1]) % 1000000; //�� ���� �ι�° ���� �������� ����.
	}
	return dp[length];
}

int main() {
	string input;

	//�Է�
	cin >> input;
	int length = input.size();

	//���� �� ���
	cout << countCase(input, length) << '\n';
}