#include <iostream>
#include <set>
using namespace std;

int n, m;
const int SIZE = 7;

int num[SIZE];
set<int> inputs; //����ڰ� �Է��� ���� ������ ��

void backtracking(int cnt) { 
	//cnt: ������ �ε���
	if (cnt == m) { //��������
		for (int i = 0; i < cnt; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (auto iter = inputs.begin(); iter != inputs.end(); iter++) {
		//���� ���� ���ʴ�� ������ ����
		num[cnt] = *iter;
		backtracking(cnt + 1); //��� ȣ��
	}
}


int main() {

	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		inputs.insert(input);
	}

	//���� + ���
	backtracking(0);
}