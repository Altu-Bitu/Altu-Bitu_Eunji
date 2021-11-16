#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n, m, ans = 64;
int cctv_size;
vector<vector<int>> room; //�繫��
vector<tuple<int, int, int>> cctv; //cctv ����: cctv ��ȣ, ��ġ(��, ��)
vector<vector<vector<int>>>cctv_dir = { //cctv ������ ���� ������ & ������(0), �Ʒ�(1), ����(2), ��(3)
	{{0},{1},{2},{3}}, //1��
	{{0,2},{1,3}}, //2��
	{{0,1},{1,2},{2,3},{3,0}}, //3��
	{{0,1,2},{1,2,3},{2,3,0},{3,0,1}}, //4��
	{{0,1,2,3}} }; //5��

//�Է� ���� �������� cctv�� ���� ������ ���� ǥ��
void check(int row, int col, vector<int>dir, vector<vector<int>>& room) {
	int dr[4] = { 0,1,0,-1 }; //������(0), �Ʒ�(1), ����(2), ��(3)
	int dc[4] = { 1,0,-1,0 };

	for (int i = 0; i < dir.size(); i++) {
		int cr = row + dr[dir[i]];
		int cc = col + dc[dir[i]];

		while (cr >= 0 && cr < n && cc >= 0 && cc < m && room[cr][cc] != 6) {
			if (room[cr][cc] == 0)
				room[cr][cc] = 7;
			cr += dr[dir[i]];
			cc += dc[dir[i]];
		}
	}

}

//�簢���� ���� ī��Ʈ
int numBlind(vector<vector<int>> &room) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (room[i][j] == 0) //���� ���ϴ�(�簢����) ���� ī��Ʈ
				cnt++;
		}
	}
	return cnt;
}

//��� ����� �� ���ؼ� �ּ� �簢������ ���� ����.
void minBlind(int num, vector<vector<int>> room) {
	if (num == cctv_size) { //��� cctv�� ���� ������ ������ ǥ���ߴٸ�
		int temp = numBlind(room);
		ans = min(ans, temp);
		return;
	}

	int type = get<0>(cctv[num]); //�� �� cctv����
	int row = get<1>(cctv[num]); //cctv ��ġ
	int col = get<2>(cctv[num]);
	vector<vector<int>> temp = room; //������ �繫�� ���� �����س��� �ӽ� �迭

	for (int i = 0; i < cctv_dir[type - 1].size(); i++) {
		check(row, col, cctv_dir[type - 1][i], room);
		minBlind(num + 1, room);
		room = temp;
	}
}

int main() {
	//�Է�
	cin >> n >> m;
	room.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5) { //cctv�� �Է¹�����
				cctv_size++;
				cctv.push_back({ room[i][j],i,j }); //cctv ������ ��Ͽ� �߰�
			}
		}
	}

	//����
	minBlind(0, room);

	//���
	cout << ans << '\n';
}