#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

//Union 연산
//사이클 발생하면 true 반환
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)  //이미 같은 집합에 있는 경우 -> 사이클 발생
		return true;

	if (parent[xp] < parent[yp]) { //새로운 루트가 xp
		parent[xp] += parent[yp]; //parent 배열 갱신
		parent[yp] = xp;
	}
	else { //새로운 루트가 yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	int ans = 0;

	//입력
	cin >> n >> m;
	parent.assign(n, -1);

	//연산
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (unionInput(a, b)) { //사이클 발생
			ans = i; //몇번째인지 저장하고 반복문 탈출
			break;
		}
	}

	//출력
	cout << ans << '\n';
}