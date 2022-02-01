#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

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

	if (xp == yp) //���� ���տ� �ִٸ� ���Ͽ� �Ұ�
		return false;
	if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { //���ο� ��Ʈ yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

pair<int,int> kruskal(int n, priority_queue<tp, vector<tp>, greater<>> pq) {
	int cnt = 0, sum = 0;

	while (cnt < n - 1 && !pq.empty()) {
		int weight = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());

		pq.pop();

		if (unionInput(x, y)) {
			cnt++;
			sum += weight;
		}
	}

	//����ġ ����, ���� ���� ��ȯ
	return { sum,cnt };
}


int main() {
	int n, m, k, x, y;
	priority_queue<tp, vector<tp>, greater<>> pq;
	vector<int>ans;

	//�Է�
	cin >> n >> m >> k;
	ans.assign(k, 0);

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		pq.push({ i,x,y });
	}

	//����
	for (int i = 0; i < k; i++) {
		parent.assign(n + 1, -1); //parent �ʱ�ȭ
		pair<int,int> result = kruskal(n, pq);

		//���� ������� Ʈ���� ������ ������ n-1���� �ƴ϶�� MST�� �ƴ϶�� �ǹ�
		if (result.second != n - 1)
			break;
		ans[i] = result.first;

		pq.pop(); //����ġ�� ���� ���� ���� ����

		//���� �׷����� ������ n-1�� ���� ���ٸ� Ʈ���� ������ ���Ѵ�.
		if (pq.size() < n - 1)
			break;
	}

	//���
	for (int i = 0; i < k; i++)
		cout << ans[i] << ' ';
}