#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> tree;

//단절점인지 판단
bool isCutPoint(int node) {
	if (tree[node].size() >= 2) //2개 이상의 정점과 연결된 정점이라면 단절점임
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;

	//입력
	cin >> n;
	tree.assign(n + 1,vector<int>(0));

	int cnt = n - 1;
	while (cnt--) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cin >> q;
	while (q--) {
		int t, k;
		cin >> t >> k;

		//연산 및 출력
		if (t == 1) {
			if (isCutPoint(k))
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else //트리의 간선은 모두 단절선
			cout << "yes\n";
		
	}
}