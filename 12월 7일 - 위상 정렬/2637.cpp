//���� ��α�: https://js1jj2sk3.tistory.com/100
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�ʿ��� �� �⺻ ��ǰ�� ���� ���ϴ� �Լ�
vector<int> countParts(int n, vector<int>& count, vector<vector<pair<int, int>>>& toys) {
	vector<vector<int>> result(n + 1, vector<int>(n + 1, 0)); //�� ��ǰ�� ����� �� �ʿ��� �⺻ ��ǰ�� ���� ����
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (!count[i]) { //�⺻ ��ǰ�̶��
			result[i][i] = 1; 
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int current_part = q.front(); //���� ��ǰ
		q.pop();

		for (int i = 0; i < toys[current_part].size(); i++) {
			int next_part = toys[current_part][i].first; //���� ��ǰ���� ���� �� �ִ� ���� ��ǰ
			int next_count = toys[current_part][i].second; //����� �� �ʿ��� ���� ��ǰ�� ����
			count[next_part]--;
			for (int j = 1; j <= n; j++) //���� ��ǰ�� ����� �� �ʿ��� �⺻ ��ǰ�� ���� ����
				result[next_part][j] += result[current_part][j] * next_count;

			if(!count[next_part]) //���� ��ǰ�� ����� �� �ʿ��� �⺻ ��ǰ�� ������ ��� �����ߴٸ�
				q.push(next_part); //ť�� ����
		}
	}
	
	return result[n];
}

int main() {
	int n, m, x, y, k;

	//�Է�
	cin >> n >> m;
	vector<vector<pair<int, int>>> toys(n + 1, vector<pair<int, int>>(0)); //�׷���(�ش� ��ǰ���� ���� �� �ִ� �߰� ��ǰ�� �ʿ��� ����)
	vector<int>count(n + 1, 0); //�ش� ��ǰ�� ����� �� �ʿ��� �⺻ Ȥ�� �߰� ��ǰ ������ ����, ��������
	while (m--) {
		cin >> x >> y >> k;
		toys[y].push_back({ x,k });
		count[x]++;
	}

	//����
	vector<int> result = countParts(n, count, toys);

	//���
	for (int i = 1; i <= n; i++) {
		if (result[i])
			cout << i << ' ' << result[i] << '\n';
	}
}