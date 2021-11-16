#include <iostream>
#include<vector>

using namespace std;
const int SIZE = 19;

//�ٵϾ��� �ٵ��ǿ� �ö� �ִ� ��� �� ��ġ�� �ֺ��� Ž�� �� �ºΰ� ������ ��ȯ�ϴ� �Լ�
int whoWin(int row, int col, vector<vector<int>>& board) {
	int ans = 0; //�ºΰ� ���� �ʾ��� ��� 0 ��ȯ
	int current = board[row][col]; //���� ��ġ�� �ִ� �ٵϾ��� ����
	//�ٵϾ��� ���� �� �ִ� ���� (������, �Ʒ�, ������ �Ʒ� �밢��, ������ �� �밢��)
	int dr[4] = { 0,1,1,-1 };
	int dc[4] = { 1,0,1,1 };

	//���⸶�� ������ �̷���� Ȯ��
	for (int k = 0; k < 4; k++) {
		int cr = row; //���� ��ġ
		int cc = col;

		//Ž�� ���� �� Ž�� ����� �ݴ� ���⿡ �ִ� �ٵϾ��� ���� Ȯ��
		//���� ������ ���ٸ� ������ �˻��� ������
		int pr = cr - dr[k];
		int pc = cc - dc[k];
		if (pr >= 0 && pr < SIZE && pc >= 0 && pc < SIZE && board[pr][pc] == current)
			continue; //�ٸ� �������� Ž��

		int cnt = 1; //���� �ٵϾ��� ���޾� � �������� ī��Ʈ�ؼ� ������ ����
		for (int i = 0; i < 5; i++) { //5������ Ȯ��(�� 6��)
			cr += dr[k];
			cc += dc[k];
			if (cr < 0 || cr >= SIZE || cc < 0 || cc >= SIZE || board[cr][cc] != current)
				break;
			cnt++;
		}

		if (cnt == 5) { //���� ���� �ٵϾ��� 5�� ���Դٸ�
			ans = current; //ans ����
			break; //���̻� Ž������ �ʾƵ� ��
		}
	}
	return ans;
}

//���� ��� ��ȯ
pair<int,pair<int,int>> game(vector<vector<int>>&board) {
	pair<int, pair<int, int>>result = { 0,{0,0} }; //first: �̱� �ٵϾ��� ����, second: �ٵϾ� ��ġ
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0)  //i�� j�� ��ġ�� �ٵϾ��� �������� �ʴٸ�
				continue;
			//�ٵϾ��� ���� ���
			int winner = whoWin(i, j, board); //�ºΰ� ������ Ȯ��
			if (winner != 0) { //�ºΰ� ���ٸ�
				result = { winner,{i + 1,j + 1} };
				return result;
			}
		}
	}
	return result;
}

int main() {
	vector<vector<int>>board(SIZE, vector<int>(SIZE, 0)); //�ٵ���

	//�Է�
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cin >> board[i][j];
	}

	//����
	pair<int, pair<int, int>>result = game(board);

	//���
	if (result.first == 0)
		cout << result.first << '\n';
	else
		cout << result.first << '\n' << result.second.first << ' ' << result.second.second << '\n';
}