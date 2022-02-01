#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<vector<int>> ground; //땅(양분 저장)

//살아있는 나무의 개수 구하는 함수
int cntTree(int n, int m, vector<vector<int>> &a, deque<tp> &trees) {
	int ans = m; //살아있는 나무의 개수
	
	vector<vector<int>> dead(n + 1, vector<int>(n + 1, 0)); //죽은 나무 저장할 벡터
	deque<tp> birth; //새로 생긴 나무 저장할 덱

	int dr[8] = { -1,-1,-1, 0, 0, 1, 1, 1 }; //번식 방향
	int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	while (m--) {
		int age = get<0>(trees.front());
		int r = get<1>(trees.front());
		int c = get<2>(trees.front());
		trees.pop_front();

		//봄(성장)
		if (age > ground[r][c]) {  //나무의 나이보다 땅의 양분이 부족하다면
			dead[r][c] += age / 2; //추가될 양분의 양에 나이의 1/2배 만큼 더 추가
			ans--;
			continue;
		}
		
		ground[r][c] -= age;
		age++;
		trees.push_back({ age,r,c });
		
		
		//가을(번식)
		if (age % 5 != 0)
			continue;

		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
				birth.push_back({ 1,nr,nc });
				ans++;
			}
		}
	}

	//양분 추가(여름, 겨울)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ground[i][j] += (a[i][j] + dead[i][j]);
	}

	//새로 난 나무들 trees 덱으로 추가
	while (!birth.empty()) {
		tp new_tree = birth.front();
		birth.pop_front();
		trees.push_front(new_tree); //나이가 제일 어리므로 앞에 추가
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, x, y, z;

	//입력
	cin >> n >> m >> k;
	ground.assign(n + 1, vector<int>(n + 1, 5)); //땅의 양분의 양
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0)); //1년마다 추가되는 양분의 양
	deque<tp> trees;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}

	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		trees.push_back({ z,x,y }); //나이, 위치 덱에 넣기
	}

	//연산
	sort(trees.begin(), trees.end()); //나이순으로 정렬

	while (k--) { //k년 반복
		m = cntTree(n, m, a, trees);
	}

	cout << m << '\n';
}