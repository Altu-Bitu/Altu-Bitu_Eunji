#include <iostream>

using namespace std;

const int SIZE = 10;

int n, temp, ans = 10000000;
int weight[10][10]; //���� i���� j�� ���� ���� ���
bool check[SIZE]; //�湮�ߴ��� üũ
int sequence[SIZE]; //�湮�� ���� ����(�ε���: �湮 ����, ��: ���� ��ȣ)

void TSP(int cnt, int temp) { //cnt: �湮�� ������ ��, temp: ��������� ���
	if (cnt == n && weight[sequence[cnt - 1]][sequence[0]]) { //��� ���ø� ��ȸ�ϰ� ó�� ���÷� ���ư� �� �ִ� ���
		ans = min(ans, temp + weight[sequence[cnt - 1]][sequence[0]]); //�ٸ� ����� ���� ���ؼ� ���� ���� ans�� ����
		return;
	}

	for (int i = 0; i < n; i++) {
		if (cnt == 0) { //���� ó�� �湮�� ������ ���
			check[i] = true; //�湮 üũ
			sequence[cnt] = i; //���� ����
			TSP(cnt + 1, 0); //��� ȣ��
			check[i] = false; //���� ���·� ���� ����(��Ž�� �����ϵ���)
			continue; //���� ���ú��� �ٽ� �湮�ؾ� �ϹǷ�
		}

		if (!check[i] && weight[sequence[cnt-1]][i]) { //������ �湮���� �ʾ����� ���� ���ÿ������� �� �� �ִ� �����̸�
			check[i] = true; 
			sequence[cnt] = i;
			TSP(cnt + 1, temp + weight[sequence[cnt - 1]][i]); //��� ȣ��

			//�ٽ� �������
			check[i] = false;
		}
	}
}

int main() {
	//�Է�
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> weight[i][j];


	//����
	TSP(0, 0);

	//���
	cout << ans << '\n';

}