#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = { -1,0,1,0 }; //�����¿� ����
int dc[4] = { 0,1,0,-1 };

//�ܺ� ���� �� -1�� �ٲ㼭 ��ȯ���ִ� �Լ�
vector<vector<int>> checkOutside(int n, int m, vector<vector<int>> paper) {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	paper[0][0] = -1;

	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i]; //�ֺ� ��ġ
			int nc = cc + dc[i];

			//���� ��ġ�� �ִ� ���� ġ� �ƴ� ���
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && paper[nr][nc] == 0) {
				q.push({ nr,nc }); //�ܺΰ���� �´�� �����Ƿ� �ܺ� ������
				paper[nr][nc] = -1; //�ܺΰ��� �� -1�� ����
			}
		}
	}
	return paper;
}

//�ܺο� �´��� ���� ���� ��ȯ�ϴ� �Լ�
int cntTouch(int n, int m, int row, int col, vector<vector<int>>& paper) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) { //�ֺ� Ž��
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (paper[nr][nc] == -1) //�ܺ� ����� �´�Ҵٸ�
			cnt++;
	}

	return cnt;
}
 

//ġ� ��� �� �ɸ��� �ð� ���ϴ� �Լ�
int meltingTime(int n, int m, vector<vector<int>> &paper) {
	int ans = 0; //�ɸ��� �ð�
	vector<vector<int>> temp; //�ܺ� ����� ���� ���⸦ ������ ���� ������ �ӽ� �迭

	while (true) {
		temp = checkOutside(n, m, paper); //�ܺ� ����� ���� ���� ����
		bool empty = true; //�����̿� ġ� �ִ��� ǥ���ϱ� ���� ����
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) { //ġ� �ִ� ĭ ã�Ƽ� ������ �˻�
				if (temp[i][j] != 1)
					continue;
				empty = false; //ġ� ����
				int cnt = cntTouch(n, m, i, j, temp); 
				if (cnt >= 2)
					paper[i][j] = 0; //�ܺΰ���� �´��� ���� ���� 2�� �̻��̶�� ��´�(����� ǥ��)
			}
		}

		if (empty) //ġ� ���ٸ�
			break; //while�� Ż��

		ans++; //1�ð� ����
	}
	
	return ans;
}
	

int main() {
	int n, m;
	
	//�Է�
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	//���� �� ���
	cout << meltingTime(n, m, paper) << '\n';
}