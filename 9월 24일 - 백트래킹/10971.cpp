#include <iostream>

using namespace std;

const int SIZE = 10;

int n, temp, ans = 10000000;
int weight[10][10]; //���� i���� j�� ���� ���� ���
bool check[SIZE]; //�湮�ߴ��� üũ
int sequence[SIZE]; //�湮�� ���� ����(�ε���: �湮 ����, ��: ���� ��ȣ)

void TSP(int cnt, int temp) { //cnt: �湮�� ������ ��
	if (cnt == n && weight[sequence[cnt - 1]][sequence[0]]) { //��� ���ø� ��ȸ
		ans = min(ans, temp + weight[sequence[cnt - 1]][sequence[0]]); //�ٸ� ����� ���� ���ؼ� ���� ���� ans�� ����
		return;
	}

	for (int i = 1; i < n; i++) {
		if (!check[i] && weight[sequence[cnt-1]][i]) {
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
	for (int i = 0; i < n; i++) { //ó�� �湮�� ���� ���� �� TSPȣ��
		check[i] = true;
		sequence[0] = i;
		TSP(1, 0);
		check[i] = false;
	}

	//���
	cout << ans << '\n';

}