#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<long long, int, int> tp;

vector<int> parent;

//find 함수
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//union 함수
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

		if (unionInput(x, y)) { //union 할 수 있다면 해당 간선 추가
			sum += weight;
			cnt++;
		}
	}

	return{ sum,cnt }; //가중치 합과 간선의 개수 반환
}

int main() {
	int n, m, a, b;
	long long c, total_cost = 0;
	priority_queue <tp, vector<tp>, greater<>> pq;

	//입력
	cin >> n >> m;
	parent.assign(n + 1, -1);
	while (m--) {
		cin >> a >> b >> c;
		total_cost += c;
		pq.push({ c,a,b });
	}

	//연산
	pair<long long, int> ans = kruskal(n, pq);

	//출력
	if (ans.second == n - 1) 
		cout << total_cost - ans.first << '\n';
	else //만약 간선의 개수가 n-1개가 아니라면 모든 건물이 연결되어 있지 않은 것
		cout << -1 << '\n';
}