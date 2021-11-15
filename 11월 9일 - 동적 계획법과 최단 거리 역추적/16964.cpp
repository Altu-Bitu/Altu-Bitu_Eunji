//���� ��α�: https://jaimemin.tistory.com/1472
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>>graph; //�׷���
vector<int> order; //�� ������ �湮 ���� & �湮üũ
vector<int>ans; //�ùٸ� �湮 ���� ������ �迭

bool compare(const int& a, const int& b) { //�� �Լ�
	return order[a] < order[b];
}

void dfs(int node) {
	if (order[node] == 0) //�湮�� �����̶�� 
		return;

	ans.push_back(node); //�ش� ���� ans�� �߰�
	order[node] = 0; //�湮 ǥ��(order �迭���� �ش� ������ �� 0���� ����)

	for (int i = 0; i < graph[node].size(); i++) { //�ش� ������ ����� �ٸ� ������ �湮
		int next_node = graph[node][i]; //������ �湮�� ����;
		dfs(next_node); //���ȣ��
	}
}

int main() {
	int n;

	//�Է�
	cin >> n;
	graph.assign(n + 1, vector<int>(0));
	vector<int>order_input(n);
	order.assign(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> order_input[i]; //�迭�� �湮 ������� ���� ����
		order[order_input[i]] = i + 1; //�������� ���°�� �湮�ϴ��� ����
	}


	//�Է¹��� �湮 ������ �������� �׷��� ����
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end(), compare);

	//����
	if(order_input[0] == 1) //1�� �������� �湮�ؾ� ��.
		dfs(1);

	//���
	if (ans == order_input)
		cout << 1 << '\n';
	else cout << 0 << '\n';
}