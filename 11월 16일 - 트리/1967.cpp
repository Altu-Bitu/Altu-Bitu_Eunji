#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> tree; //트리
vector<bool> visited; //방문체크
int ans = 0; //답

//지름 구하는 함수
void maxDistance(int node, int sum) {
	if (tree[node].size() == 1) { //루트 노드에 도달하면
		ans = max(sum, ans); //최댓값 갱신
		return;
	}

	//노드에 연결된 간선의 수만큼 탐색
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first; //다음에 탐색할 노드
		if (visited[next]) { //방문한 노드라면
			continue;
		}
		visited[node] = true; //현재 노드 방문 표시
		sum += tree[node][i].second; //경로 길이 갱신

		maxDistance(next, sum); //다음 노드 방문

		visited[node] = false; //방문 후 방문체크 해제
		sum -= tree[node][i].second; //경로 길이 원래대로
	}
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
	//리프 노드에서 시작
	while (n >= 1) {
		if (tree[n].size() == 1) {
			visited[n] = true;
			int next = tree[n][0].first;
			int weight = tree[n][0].second;
			maxDistance(next, weight);
		}
		n--;
	}

	//출력
	cout << ans << '\n';
}