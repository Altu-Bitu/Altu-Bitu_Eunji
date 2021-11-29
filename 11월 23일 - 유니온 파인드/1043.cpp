#include <iostream>
#include <vector>

using namespace std;

vector<int>parent;
vector<bool>know; //진실을 알고 있으면 true

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;

	if (know[xp] || know[yp]) //한 사람이라도 안다면 거짓말을 하지 못함 (파티 참석한 사람 모두가 진실을 알게 됨)
		know[xp] = know[yp] = true;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int cntParty(vector<vector<int>> party, int m) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int p = findParent(party[i][0]); //i번째 파티에 참석한 사람들의 집합에서의 루트

		if (!know[p]) //만약 루트에 해당하는 사람(같이 파티에 참석한 사람)이 진실을 알지 못한다면 허풍 떨어도 됨.
			cnt++;
	}
	return cnt;
}

int main() {
	int n, m, num;
	int cnt_know;

	//입력
	cin >> n >> m;
	parent.assign(n + 1, -1);
	know.assign(n + 1, false);
	vector<vector<int>> party(m); //파티마다 참석한 사람 저장

	cin >> cnt_know;
	while (cnt_know--) { //알고 있는 사람 입력받아서 know 갱신
		cin >> num;
		know[num] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> num; //i번째 파티에 num명의 사람 참석
		for (int j = 0; j < num; j++) {
			int input; //참석한 사람의 번호
			cin >> input;
			party[i].push_back(input); //파티 명단에 넣기
		}
		for (int j = 0; j < num - 1; j++) //같은 파티에 참석한 사람들끼리 하나의 집합으로 묶음.
			unionInput(party[i][j], party[i][j + 1]);
	}

	//연산 및 출력
	cout << cntParty(party, m) << '\n';
}