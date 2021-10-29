//참고 블로그
//https://jaimemin.tistory.com/623

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
vector<vector<bool>> check; //방문한 위치인지 체크할 벡터


int maxWithDfs(int n, int m, int x, int y, int cnt) {	
	if (cnt == 3) //테트로미노가 완성
		return paper[x][y];

	vector<int> dx = { 0, 0, 1, -1 }; //행의 이동 방향(아래, 위)
	vector<int> dy = { 1, -1, 0, 0 }; //열의 이동 방향(오른쪽, 왼쪽)

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		//다음 위치(행, 열)
		int nx = x + dx[i];
		int ny = y + dy[i];

		//다음 위치가 종이 범위 안에 있다면
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !check[nx][ny]) {
			check[nx][ny] = true; //방문 표시
			sum = max(sum, paper[x][y] + maxWithDfs(n, m, nx, ny, cnt + 1)); //현재 구한 값과 지금까지의 최댓값과 비교하여 최댓값 갱신
			check[nx][ny] = false; //다시 원래대로
		}
	}
	return sum;
}

int maxWithoutDfs(int n, int m, int x, int y) {
	int sum = 0;
	int temp;
	if (x >= 1 && y >= 1 && y < m - 1) { //'ㅗ' 모양
		temp = paper[x - 1][y] + paper[x][y - 1] + paper[x][y] + paper[x][y + 1];
		sum = max(sum, temp);
	}
	if (y >= 1 && y < m - 1 && x < n - 1) { //'ㅜ' 모양
		temp = paper[x][y - 1] + paper[x][y] + paper[x][y + 1] + paper[x + 1][y];
		sum = max(sum, temp);
	}
	if (x >= 1 && x < n - 1 && y < m - 1) { //'ㅏ' 모양
		temp = paper[x - 1][y] + paper[x][y] + paper[x + 1][y] + paper[x][y + 1];
		sum = max(sum, temp);
	}
	if (x >= 1 && x < n - 1 && y >= 1) { //'ㅓ' 모양
		temp = paper[x - 1][y] + paper[x][y] + paper[x + 1][y] + paper[x][y - 1];
		sum = max(sum, temp);
	}

	return sum;
}

int main() {
	int n, m;

	//입력
	cin >> n >> m;
	paper.assign(n, vector<int>(m));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}
	
	//연산
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//행 혹은 열을 하나씩 추가 또는 감소하며 만들 수 있는 테트로미노의 경우 (ㅁ,ㄱ, N 모양)
			check[i][j] = true;
			ans = max(ans, maxWithDfs(n, m, i, j, 0));
			check[i][j] = false;

			//행과 열을 모두 추가 또는 감소해야 만들 수 있는 테트로미노의 경우
			ans = max(ans, maxWithoutDfs(n, m, i, j));
			
		}
	}

	//출력
	cout << ans << '\n';
}