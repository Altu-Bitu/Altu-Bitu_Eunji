#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minTime(int n, int k) {
	int time = 0;
	vector<bool>visited(100001, false); //�湮 üũ�� ����
	queue<pair<int, int>>q; //Ž���� ���� ť(��ġ, �ð�)
	q.push(make_pair(n, 0)); //�������� ó�� ��ġ ť�� ����
	visited[n] = true; //ó�� ��ġ �湮 ǥ��

	while (!q.empty()) {
		int cur_position = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		if (cur_position == k) //���� ��ġ�� �����ߴٸ�
			return cur_time;
		
		if (cur_position + 1 <= 100000 && !visited[cur_position + 1]) { //�� ĭ ������ �̵�
			q.push(make_pair(cur_position + 1, cur_time + 1));
			visited[cur_position + 1] = true;
		}
		if (cur_position - 1 >= 0 && !visited[cur_position - 1]) { //�ڷ� �̵�
			q.push(make_pair(cur_position - 1, cur_time + 1));
			visited[cur_position - 1] = true;
		}
		if (cur_position * 2 <= 100000 && cur_position * 2 > 0 && !visited[cur_position * 2]) { //2�� ������ �̵�
			q.push(make_pair(cur_position * 2, cur_time + 1));
			visited[cur_position * 2] = true;
		}
	}
}

int main() {
	int n, k;

	//�Է�
	cin >> n >> k;

	//���� �� ���
	cout << minTime(n, k) << '\n';
}