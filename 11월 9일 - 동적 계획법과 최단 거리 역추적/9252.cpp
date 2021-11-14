//���� ��α�: https://far-simple.tistory.com/38
#include <iostream>
#include <vector>

using namespace std;

//dp �迭 �̿��� ���� �κ� ���� ���ϴ� �Լ�
string back(string input1, int size1, int size2, int max_length, vector<vector<int>> &dp) {
	string ans = ""; //�κ� ����
	int idx1 = size1, idx2 = size2; //dp �迭�� ����� �ε���, ���� ��ġ(������ �Ʒ����� ����)
	int length = max_length; //�κ� ������ ����

	//�κ� ������ �ϼ����� ������ �ݺ�
	while (length > 0) {
		if (dp[idx1][idx2] == dp[idx1][idx2 - 1]) //���� ���� �ε��������� dp ���� ������ dp ���� ���ٸ� ���ʿ��� �� ��
			idx2--; //�������� �̵�
		else if (dp[idx1][idx2] == dp[idx1 - 1][idx2]) //���� ���� �ε��������� dp ���� ������ dp ���� ���ٸ� ������ �� ��
			idx1--; //���� ��ġ�� �������� �̵�
		else { //���� ���� �ε��������� dp ���� ���� ������ �� ���̶��
			ans = input1[--idx1] + ans; //�κ� ���� ����
			idx2--; //���� ��ġ ����(���� ����)
			length--; //������ ä������ ���� �ϳ� ����
		}
	}
	return ans;
}

//���� �� �κ� ������ ���� ���ϴ� �Լ�
int lcs(string input1, string input2, vector<vector<int>> &dp) {
	int size1 = input1.size(); //���ڿ� 1�� ����
	int size2 = input2.size(); //���ڿ� 2�� ����

	for (int i = 1; i <= size1; i++) { //dp �迭�� ��, ���� �ε��� 1���� ����
		for (int j = 1; j <= size2; j++) {
			if (input1[i - 1] == input2[j - 1]) //���ڰ� ���� ������
				dp[i][j] = dp[i - 1][j - 1] + 1; //���� ���� ��(�ش� ���ڰ� ���ԵǱ� �� ��ġ) + 1
			else //���ڰ� �ٸ��ٸ�
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //���� Ȥ�� ���ʿ��� �� ū ���� �����´�.
		}
	}

	return dp[size1][size2];
}

int main() {
	string input1, input2;

	//�Է�
	cin >> input1 >> input2;

	int size1 = input1.size();
	int size2 = input2.size();
	vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0)); //dp �迭
	
	//���� �� ���
	int max_length = lcs(input1, input2, dp);
	cout << max_length << '\n';
	
	if (max_length != 0)  //�κ� ������ ���̰� 0�� �ƴ϶�� �κ� ���� ���
		cout << back(input1, size1, size2, max_length, dp) << '\n';
}