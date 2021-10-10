//참고 블로그
//https://nim-code.tistory.com/100

#include <iostream>
#include <vector>

using namespace std;

int ans = -1;

//최대 에너지 구하는 함수, n: 구슬 개수, total: 에너지 총합, w: 구슬 무게
void maxEnergy(int n, int total, vector<int> w) {
	if (n == 2) { //남은 구슬 2개일 때 (기저 조건)
		ans = max(ans, total); //최댓값 갱신
		return;
	}
	//두번째 구슬부터 n-1번째 구슬까지 (인덱스 1 ~ n-2) 뽑기
	for (int i = 1; i < n - 1; i++) {
		int temp = w[i]; //뽑는 구슬
		total += w[i - 1] * w[i + 1]; //에너지 총합 갱신
		w.erase(w.begin() + i); //뽑은 구슬 제거
		maxEnergy(n - 1, total, w); //n - 1개의 구슬을 가지고 최댓값 구하기
		w.insert(w.begin() + i, temp); // 다시 구슬 추가
		total -= w[i - 1] * w[i + 1]; //에너지 총합 원래대로

	}
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];


	//연산 
	maxEnergy(n, 0, w);

	//출력
	cout << ans << '\n';
}