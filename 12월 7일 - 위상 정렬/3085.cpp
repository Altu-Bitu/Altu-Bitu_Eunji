#include <iostream>
#include <vector>

using namespace std;

//���η� ���� ĵ�� ���� �Լ�
int countCol(int n, vector<vector<char>>& candy) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int length = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) //������(�翷) �� ĵ���� ���� ���ٸ�
				length++; //���� �߰�
			else { //�׷��� �ʴٸ�
				ans = max(length, ans); //�ִ� ���� ����
				length = 1;
			}
		}
		ans = max(ans, length);
	}

	return ans;
}

 //���η� ���� ĵ�� ���� �Լ�
int countRow(int n, vector<vector<char>>& candy) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int length = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) //������(���Ʒ�) �� ĵ���� ���� ���ٸ�
				length++;
			else {
				ans = max(length, ans);
				length = 1;
			}
		}
		ans = max(ans, length);
	}
	return ans;
}

//���� ĵ���� �ִ� ���� ���ϴ� �Լ�
int maxCount(int n, vector<vector<char>>& candy) {
	int ans = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] != candy[i][j + 1]) { //������ ������ ĵ�� ���� �ٸ��ٸ�
				swap(candy[i][j], candy[i][j + 1]); //��ġ �ٲ�
				temp = max(countCol(n, candy), countRow(n, candy)); //���� �� ĵ���� ���� ���� ���ϱ�
				ans = max(ans, temp);
				swap(candy[i][j], candy[i][j + 1]); //���ڸ���
			}
			
			if (candy[j][i] != candy[j + 1][i]) { //���Ʒ��� ������ ĵ�� ���� �ٸ��ٸ�
				swap(candy[j][i], candy[j + 1][i]);
				temp = max(countCol(n, candy), countRow(n, candy));
				ans = max(ans, temp);
				swap(candy[j][i], candy[j + 1][i]);
			}
		}
	}
	return ans;
}

int main() {
	int n;

	//�Է�
	cin >> n;
	vector<vector<char>> candy(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> candy[i][j];
	}
	
	//���� �� ���
	cout << maxCount(n, candy) << '\n';
}