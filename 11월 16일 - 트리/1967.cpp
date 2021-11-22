#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> tree; //트리
vector<bool> visited; //방문체크
int ans = 0; //답
int far_node = 0; //지름의 양 끝 노드

//dfs 함수
void dfs(int node, int sum) {
	if (visited[node]) //이미 방문한 노드라면
		return;

	visited[node] = true; //방문 표시

	if (ans < sum) { //현재까지의 거리보다 더 거리가 먼 노드라면
		ans = sum; //거리 갱신
		far_node = node; //노드 갱신
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int next_node = tree[node][i].first;
		int next_sum = sum + tree[node][i].second;
		dfs(next_node, next_sum);
	}

	visited[node] = false; //방문 표시 해제
}

int main() {
	int n;

	//입력
	cin >> n;
	tree.assign(n + 1, vector<pair<int, int>>(0));
	visited.assign(n + 1, false);
	int cnt = n - 1;
	while (cnt--) {
		int a, b, w;
		cin >> a >> b >> w;
		tree[a].emplace_back(b, w);
		tree[b].emplace_back(a, w);
	}

	//연산
	//루트 노드에서 가장 멀리 있는 리프 노드 찾기
	dfs(1, 0);

	//위에서 찾은 리프 노드에서 가장 먼 노드 찾기 & 그때의 거리(지름) 구하기
	dfs(far_node, 0);

	//출력
	cout << ans << '\n';
}