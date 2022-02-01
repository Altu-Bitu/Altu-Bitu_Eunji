#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

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

	if (xp == yp) //같은 집합에 있다면 유니온 불가
		return false;
	if (parent[xp] < parent[yp]) { //새로운 루트 xp
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { //새로운 루트 yp
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

	//가중치 총합, 간선 개수 반환
	return { sum,cnt };
}


int main() {
	int n, m, k, x, y;
	priority_queue<tp, vector<tp>, greater<>> pq;
	vector<int>ans;

	//입력
	cin >> n >> m >> k;
	ans.assign(k, 0);

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		pq.push({ i,x,y });
	}

	//연산
	for (int i = 0; i < k; i++) {
		parent.assign(n + 1, -1); //parent 초기화
		pair<int,int> result = kruskal(n, pq);

		//만약 만들어진 트리의 간선의 개수가 n-1개가 아니라면 MST가 아니라는 의미
		if (result.second != n - 1)
			break;
		ans[i] = result.first;

		pq.pop(); //가중치가 가장 작은 간선 제거

		//만약 그래프의 간선이 n-1개 보다 적다면 트리를 만들지 못한다.
		if (pq.size() < n - 1)
			break;
	}

	//출력
	for (int i = 0; i < k; i++)
		cout << ans[i] << ' ';
}