//참고 블로그: https://js1jj2sk3.tistory.com/100
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//필요한 총 기본 부품의 개수 구하는 함수
vector<int> countParts(int n, vector<int>& count, vector<vector<pair<int, int>>>& toys) {
	vector<vector<int>> result(n + 1, vector<int>(n + 1, 0)); //각 부품을 만드는 데 필요한 기본 부품의 개수 저장
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (!count[i]) { //기본 부품이라면
			result[i][i] = 1; 
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int current_part = q.front(); //현재 부품
		q.pop();

		for (int i = 0; i < toys[current_part].size(); i++) {
			int next_part = toys[current_part][i].first; //현재 부품으로 만들 수 있는 다음 부품
			int next_count = toys[current_part][i].second; //만드는 데 필요한 현재 부품의 개수
			count[next_part]--;
			for (int j = 1; j <= n; j++) //다음 부품을 만드는 데 필요한 기본 부품의 개수 갱신
				result[next_part][j] += result[current_part][j] * next_count;

			if(!count[next_part]) //다음 부품을 만드는 데 필요한 기본 부품의 개수를 모두 저장했다면
				q.push(next_part); //큐에 삽입
		}
	}
	
	return result[n];
}

int main() {
	int n, m, x, y, k;

	//입력
	cin >> n >> m;
	vector<vector<pair<int, int>>> toys(n + 1, vector<pair<int, int>>(0)); //그래프(해당 부품으로 만들 수 있는 중간 부품과 필요한 개수)
	vector<int>count(n + 1, 0); //해당 부품을 만드는 데 필요한 기본 혹은 중간 부품 종류의 개수, 진입차수
	while (m--) {
		cin >> x >> y >> k;
		toys[y].push_back({ x,k });
		count[x]++;
	}

	//연산
	vector<int> result = countParts(n, count, toys);

	//출력
	for (int i = 1; i <= n; i++) {
		if (result[i])
			cout << i << ' ' << result[i] << '\n';
	}
}