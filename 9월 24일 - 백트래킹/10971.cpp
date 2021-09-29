#include <iostream>

using namespace std;

const int SIZE = 10;

int n, temp, ans = 10000000;
int weight[10][10]; //도시 i에서 j로 가기 위한 비용
bool check[SIZE]; //방문했는지 체크
int sequence[SIZE]; //방문한 순서 저장(인덱스: 방문 순서, 값: 도시 번호)

void TSP(int cnt, int temp) { //cnt: 방문한 도시의 수, temp: 현재까지의 비용
	if (cnt == n && weight[sequence[cnt - 1]][sequence[0]]) { //모든 도시를 순회하고 처음 도시로 돌아갈 수 있는 경우
		ans = min(ans, temp + weight[sequence[cnt - 1]][sequence[0]]); //다른 경우의 비용과 비교해서 작은 값을 ans에 저장
		return;
	}

	for (int i = 0; i < n; i++) {
		if (cnt == 0) { //제일 처음 방문한 도시인 경우
			check[i] = true; //방문 체크
			sequence[cnt] = i; //순서 저장
			TSP(cnt + 1, 0); //재귀 호출
			check[i] = false; //원래 상태로 돌려 놓음(재탐색 가능하도록)
			continue; //다음 도시부터 다시 방문해야 하므로
		}

		if (!check[i] && weight[sequence[cnt-1]][i]) { //이전에 방문하지 않았으며 직전 도시에서부터 올 수 있는 도시이면
			check[i] = true; 
			sequence[cnt] = i;
			TSP(cnt + 1, temp + weight[sequence[cnt - 1]][i]); //재귀 호출

			//다시 원래대로
			check[i] = false;
		}
	}
}

int main() {
	//입력
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> weight[i][j];


	//연산
	TSP(0, 0);

	//출력
	cout << ans << '\n';

}