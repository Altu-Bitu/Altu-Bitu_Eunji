//참고 블로그: https://jaimemin.tistory.com/1472
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>>graph; //그래프
vector<int> order; //각 정점의 방문 순서 & 방문체크
vector<int>ans; //올바른 방문 순서 저장할 배열

bool compare(const int& a, const int& b) { //비교 함수
	return order[a] < order[b];
}

void dfs(int node) {
	if (order[node] == 0) //방문한 정점이라면 
		return;

	ans.push_back(node); //해당 정점 ans에 추가
	order[node] = 0; //방문 표시(order 배열에서 해당 정점의 값 0으로 변경)

	for (int i = 0; i < graph[node].size(); i++) { //해당 정점에 연결된 다른 정점들 방문
		int next_node = graph[node][i]; //다음에 방문할 정점;
		dfs(next_node); //재귀호출
	}
}

int main() {
	int n;

	//입력
	cin >> n;
	graph.assign(n + 1, vector<int>(0));
	vector<int>order_input(n);
	order.assign(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> order_input[i]; //배열에 방문 순서대로 정점 저장
		order[order_input[i]] = i + 1; //정점마다 몇번째로 방문하는지 저장
	}


	//입력받은 방문 순서를 기준으로 그래프 정렬
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end(), compare);

	//연산
	if(order_input[0] == 1) //1번 정점부터 방문해야 함.
		dfs(1);

	//출력
	if (ans == order_input)
		cout << 1 << '\n';
	else cout << 0 << '\n';
}