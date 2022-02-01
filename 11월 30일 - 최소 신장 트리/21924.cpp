#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<long long, int, int> tp;

vector<int> parent;

//find �Լ�
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//union �Լ�
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	
	if (xp == yp)
		return false;
	if (xp < yp) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

pair<long long,int> kruskal(int n, priority_queue<tp, vector<tp>, greater<>> &pq) {
	int cnt = 0;
	long long sum = 0;
	while (cnt < n - 1 && !pq.empty()) {
		long long weight = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (unionInput(x, y)) { //union �� �� �ִٸ� �ش� ���� �߰�
			sum += weight;
			cnt++;
		}
	}

	return{ sum,cnt }; //����ġ �հ� ������ ���� ��ȯ
}

int main() {
	int n, m, a, b;
	long long c, total_cost = 0;
	priority_queue <tp, vector<tp>, greater<>> pq;

	//�Է�
	cin >> n >> m;
	parent.assign(n + 1, -1);
	while (m--) {
		cin >> a >> b >> c;
		total_cost += c;
		pq.push({ c,a,b });
	}

	//����
	pair<long long, int> ans = kruskal(n, pq);

	//���
	if (ans.second == n - 1) 
		cout << total_cost - ans.first << '\n';
	else //���� ������ ������ n-1���� �ƴ϶�� ��� �ǹ��� ����Ǿ� ���� ���� ��
		cout << -1 << '\n';
}