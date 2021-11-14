#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n, m, ans = 64;
int cctv_size;
vector<vector<int>> room; //�繫��
vector<tuple<int, int, int>> cctv; //cctv ����: cctv ��ȣ, ��ġ(��, ��)

//�Է� ���� �������� cctv�� ���� ������ ���� ǥ��
void check(int row, int col, vector<int>dir, vector<vector<int>> &room) {
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == 0) { //������
			for (int j = col + 1; j < m; j++) {
				if (room[row][j] == 6)
					break; //���̸� ���̻� üũ �Ұ�.
				if (room[row][j] == 0) //�� �����̸�
					room[row][j] = 7; //cctv ���� ����(7�� ǥ��)
			}
		}
		else if (dir[i] == 1) { //�Ʒ���
			for (int j = row + 1; j < n; j++) {
				if (room[j][col] == 6)
					break;
				if (room[j][col] == 0)
					room[j][col] = 7;
			}
		}
		else if (dir[i] == 2) { //����
			for (int j = col - 1; j >= 0; j--) {
				if (room[row][j] == 6)
					break;
				if (room[row][j] == 0)
					room[row][j] = 7;
			}
		}
		else { //����
			for (int j = row - 1; j >= 0; j--) {
				if (room[j][col] == 6)
					break;
				if (room[j][col] == 0)
					room[j][col] = 7;
			}
		}
	}	
}

//��� ����� �� ���ؼ� �ּ� �簢������ ���� ����.
void minBlind(int num, vector<vector<int>> room) {
	if (num == cctv_size) { //��� cctv�� ���� ������ ������ ǥ���ߴٸ�
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (room[i][j] == 0) //���� ���ϴ�(�簢����) ���� ī��Ʈ
					cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int type = get<0>(cctv[num]); //�� �� cctv����
	int row = get<1>(cctv[num]); //cctv ��ġ
	int col = get<2>(cctv[num]);
	vector<vector<int>> temp = room; //������ �繫�� ���� �����س��� �ӽ� �迭

	if (type == 1) { //1�� cctv
		for (int i = 0; i < 4; i++) { //������ cctv ���� �װ���
				//�ϳ��� cctv�� �� ������ ����Ų��.
			vector<int>dir = { i };
			check(row, col, dir, room);
			minBlind(num + 1, room); //���� cctv�� ���� ���� ���� üũ
			room = temp; //�繫�� ���� �������
		}
	}
	else if (type == 2) { //2�� cctv
		for (int i = 0; i < 2; i++) { //������ cctv ���� �ΰ���
		//�ϳ��� cctv�� �� ���� ������ ����Ų��.
			vector<int>dir = { i, i + 2 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else if (type == 3) { //3�� cctv
		for (int i = 0; i < 4; i++) { //������ cctv ���� �װ���
			//�ϳ��� cctv�� �� ���� ������ ����Ų��.
			vector<int>dir = { i, (i + 1) % 4 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else if (type == 4) { //4�� cctv
		for (int i = 0; i < 4; i++) { //������ cctv ���� �װ��� 
			//�ϳ��� cctv�� �� ���� ������ ����Ų��.
			vector<int>dir = { i, (i + 1) % 4, (i + 2) % 4 };
			check(row, col, dir, room);
			minBlind(num + 1, room);
			room = temp;
		}
	}
	else { //5�� cctv
		//������ cctv ������ �Ѱ���, �ϳ��� cctv�� ��� ���� ����Ŵ.
		vector<int>dir = { 0,1,2,3 };
		check(row, col, dir, room);
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