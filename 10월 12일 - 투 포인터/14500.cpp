//���� ��α�
//https://jaimemin.tistory.com/623

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
vector<vector<bool>> check; //�湮�� ��ġ���� üũ�� ����


int maxWithDfs(int n, int m, int x, int y, int cnt) {	
	if (cnt == 3) //��Ʈ�ι̳밡 �ϼ�
		return paper[x][y];

	vector<int> dx = { 0, 0, 1, -1 }; //���� �̵� ����(�Ʒ�, ��)
	vector<int> dy = { 1, -1, 0, 0 }; //���� �̵� ����(������, ����)

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		//���� ��ġ(��, ��)
		int nx = x + dx[i];
		int ny = y + dy[i];

		//���� ��ġ�� ���� ���� �ȿ� �ִٸ�
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !check[nx][ny]) {
			check[nx][ny] = true; //�湮 ǥ��
			sum = max(sum, paper[x][y] + maxWithDfs(n, m, nx, ny, cnt + 1)); //���� ���� ���� ���ݱ����� �ִ񰪰� ���Ͽ� �ִ� ����
			check[nx][ny] = false; //�ٽ� �������
		}
	}
	return sum;
}

int maxWithoutDfs(int n, int m, int x, int y) {
	int sum = 0;
	int temp;
	if (x >= 1 && y >= 1 && y < m - 1) { //'��' ���
		temp = paper[x - 1][y] + paper[x][y - 1] + paper[x][y] + paper[x][y + 1];
		sum = max(sum, temp);
	}
	if (y >= 1 && y < m - 1 && x < n - 1) { //'��' ���
		temp = paper[x][y - 1] + paper[x][y] + paper[x][y + 1] + paper[x + 1][y];
		sum = max(sum, temp);
	}
	if (x >= 1 && x < n - 1 && y < m - 1) { //'��' ���
		temp = paper[x - 1][y] + paper[x][y] + paper[x + 1][y] + paper[x][y + 1];
		sum = max(sum, temp);
	}
	if (x >= 1 && x < n - 1 && y >= 1) { //'��' ���
		temp = paper[x - 1][y] + paper[x][y] + paper[x + 1][y] + paper[x][y - 1];
		sum = max(sum, temp);
	}

	return sum;
}

int main() {
	int n, m;

	//�Է�
	cin >> n >> m;
	paper.assign(n, vector<int>(m));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}
	
	//����
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//�� Ȥ�� ���� �ϳ��� �߰� �Ǵ� �����ϸ� ���� �� �ִ� ��Ʈ�ι̳��� ��� (��,��, N ���)
			check[i][j] = true;
			ans = max(ans, maxWithDfs(n, m, i, j, 0));
			check[i][j] = false;

			//��� ���� ��� �߰� �Ǵ� �����ؾ� ���� �� �ִ� ��Ʈ�ι̳��� ���
			ans = max(ans, maxWithoutDfs(n, m, i, j));
			
		}
	}

	//���
	cout << ans << '\n';
}