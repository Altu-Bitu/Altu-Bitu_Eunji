//���� ��α�: https://blog.naver.com/PostView.nhn?blogId=fbfbf1&logNo=222473456076
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_TIME = 401;
const int N = 21;

vector<vector<int>> space;
vector<vector<int>> check; //�湮 üũ & �̵� �ð� ���� �迭
int n;
int min_time; //�� ����⸦ ã�� �� �ɸ� �ּ� �ð�

pair<int, int> bfs(int row, int col, int size, pair<int, int> fish_pos) {
	int dr[4] = { -1,1,0,0 }; //��, ��, ��, ��
	int dc[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q; //bfs Ž���� ���� ť
	q.push({ row,col }); //����� ���� ��ġ ť�� push

	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) { //���� ��� Ž��
			int nr = cr + dr[i]; //���� �湮 ��ġ
			int nc = cc + dc[i];

			//���� ��ġ�� ������ �Ѿ�ų� �̹� �湮�� ���̰ų� ����� ũ�⺸�� ū ����Ⱑ �ִ� ���� ��� continue
			if (nr < 0 || nr >= n || nc<0 || nc >= n || check[nr][nc] != -1 || space[nr][nc] > size)
				continue;

			check[nr][nc] = check[cr][cc] + 1; //nr, nc�� �̵� & �ð� ����

			//���� ���� �� �ִ� ����Ⱑ �ִ� ��ġ�� ���
			if (space[nr][nc] > 0 && space[nr][nc] < size) {
				if (min_time > check[nr][nc]) { //���ݱ����� �ּ� Ž�� �ð����� �� ª�� �ð��� �ҿ��ߴٸ�
					min_time = check[nr][nc]; //�ּ� �ð� ����
					fish_pos = { nr,nc }; //���� ����� ����
				}
				else if (min_time == check[nr][nc]) { //�ּ� �ð��� ���� �ð� �ҿ��� ���
					if (fish_pos.first > nr && fish_pos.second > nc) //���� ���� �ִ� ���
						fish_pos = { nr,nc };
					else if (fish_pos.first > nr) //�׷��� ������ ���ʿ� �ִ� ���
						fish_pos = { nr,nc }; //���� ����� ����
				}
			}

			q.push({ nr,nc });
		}
	}

	return fish_pos;
}

int eating(int row, int col) {
	int time = 0;
	int size = 2;
	int cnt_fish = 0; //���� ����� ��
	pair<int, int> fish_pos; //�Ʊ� �� ���� ����� ��ġ

	while (true) {
		//�ʱ�ȭ
		min_time = MAX_TIME;
		fish_pos = { N, N };
		check.assign(n, vector<int>(n, -1));
		check[row][col] = 0;

		fish_pos = bfs(row, col, size, fish_pos); //����� Ž��

		if (fish_pos == make_pair(N, N)) //���� �� �ִ� ����Ⱑ ���� ���
			break;

		//���� �� �ִ� ����� �߰�
		time += check[fish_pos.first][fish_pos.second]; //�ð� ����
		cnt_fish++; //���� ����� �� ����

		if (cnt_fish == size) { //�� ũ��� ���� ���� ����� ���� ���
			size++; //�� ũ�� ����
			cnt_fish = 0; //���� ����� �� �ʱ�ȭ
		}

		space[fish_pos.first][fish_pos.second] = 0; //�ش� ��ġ ����� ����

		row = fish_pos.first; // �Ʊ� ��� ��ġ ����
		col = fish_pos.second;;
	}

	return time;
}

int main() {
	int r, c;

	//�Է�
	cin >> n;
	space.assign(n, vector<int>(n));
	check.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				r = i; 
				c = j;
				space[r][c] = 0;
				check[r][c] = 0;
			}
		}
	}
	
	//���� �� ���
	cout << eating(r, c) << "\n";
}