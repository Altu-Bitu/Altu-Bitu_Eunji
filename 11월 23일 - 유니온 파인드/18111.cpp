#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> space;

pair<int, int> moveBlock(int height, int n, int m, int b) {
	pair<int, int> info = { 0, b };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = height - space[i][j]; //필요한 블록 양
			info.second -= num; //남은 블록에서 필요한 블록 수 빼기
			if (num < 0) //필요한 블록 수가 음수인 경우(블록을 제거하는 경우)
				info.first = info.first + (-2) * num; //시간 갱신
			else if (num > 0) //블록 추가하는 경우
				info.first += num; //시간 갱신
		}
	}
	return info;
}

pair<int, int> ground(int n, int m, int b, int max_height, int min_height) {
	pair<int, int> ans = {2e8, 0}; //시간, 높이 순

	//최소 높이부터 최대 높이까지 모두 걸리는 시간 검사
	for (int i = min_height; i <= max_height; i++) {

		pair<int, int> temp = moveBlock(i, n, m, b);
		
		if (temp.second >= 0) { //남은 블록이 0개 이상인 경우
			if (temp.first <= ans.first){ //정답 갱신
				ans.first = temp.first;
				ans.second = max(ans.second, i);
			}
		}
	}
	return ans;
}

int main() {
	int n, m, b;
	int max_height = 0;
	int min_height = 256;

	//입력
	cin >> n >> m >> b;
	space.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
			max_height = max(max_height, space[i][j]);
			min_height = min(min_height, space[i][j]);
		}
	}

	//연산
	pair<int, int> ans = ground(n, m, b, max_height, min_height);

	//출력
	cout << ans.first << ' ' << ans.second << '\n';
}