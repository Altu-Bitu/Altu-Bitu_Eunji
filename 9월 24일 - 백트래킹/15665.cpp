#include <iostream>
#include <set>
using namespace std;

int n, m;
const int SIZE = 7;

int num[SIZE];
set<int> inputs; //사용자가 입력한 수를 저장할 셋

void backtracking(int cnt) { 
	//cnt: 수열의 인덱스
	if (cnt == m) { //기저조건
		for (int i = 0; i < cnt; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (auto iter = inputs.begin(); iter != inputs.end(); iter++) {
		//셋의 원소 차례대로 수열에 저장
		num[cnt] = *iter;
		backtracking(cnt + 1); //재귀 호출
	}
}


int main() {

	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		inputs.insert(input);
	}

	//연산 + 출력
	backtracking(0);
}