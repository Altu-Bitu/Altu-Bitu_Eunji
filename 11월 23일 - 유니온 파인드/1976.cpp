#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//find 함수
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//union 함수
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[yp];
		parent[xp] = yp;
	}
}

//여행 계획대로 방문 가능한지 판별하여 반환하는 함수
//여행 계획에 속한 도시들이 모두 같은 집합 즉, 같은 루트를 가지면 방문 가능.
bool canVisit(int m, vector<int>city) {
	int parent = findParent(city[0]);

	for (int i = 1; i < m; i++) { //도시들이 모두 같은 집합에 속하는지 검사
		if (parent != findParent(city[i]))
			return false;
	}
	return true;
}

int main() {
	int n, m, input;

	//입력
	cin >> n >> m;
	parent.assign(n + 1, -1);
	vector<int>city(m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input && i < j)
				unionInput(i, j);
		}
	}

	for (int i = 0; i < m; i++)
		cin >> city[i]; //여행 계획

	//연산 및 출력
	if (canVisit(m, city))
		cout << "YES\n";
	else
		cout << "NO\n";
}