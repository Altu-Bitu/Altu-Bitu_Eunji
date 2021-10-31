#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minTime(int n, int k) {
	int time = 0;
	vector<bool>visited(100001, false); //방문 체크할 벡터
	queue<pair<int, int>>q; //탐색을 위한 큐(위치, 시간)
	q.push(make_pair(n, 0)); //수빈이의 처음 위치 큐에 삽입
	visited[n] = true; //처음 위치 방문 표시

	while (!q.empty()) {
		int cur_position = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		if (cur_position == k) //동생 위치에 도달했다면
			return cur_time;
		
		if (cur_position + 1 <= 100000 && !visited[cur_position + 1]) { //한 칸 앞으로 이동
			q.push(make_pair(cur_position + 1, cur_time + 1));
			visited[cur_position + 1] = true;
		}
		if (cur_position - 1 >= 0 && !visited[cur_position - 1]) { //뒤로 이동
			q.push(make_pair(cur_position - 1, cur_time + 1));
			visited[cur_position - 1] = true;
		}
		if (cur_position * 2 <= 100000 && cur_position * 2 > 0 && !visited[cur_position * 2]) { //2배 앞으로 이동
			q.push(make_pair(cur_position * 2, cur_time + 1));
			visited[cur_position * 2] = true;
		}
	}
}

int main() {
	int n, k;

	//입력
	cin >> n >> k;

	//연산 및 출력
	cout << minTime(n, k) << '\n';
}