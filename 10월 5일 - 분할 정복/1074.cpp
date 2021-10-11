#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int r, c;
int ans;


//몇사분면에 속하는지
//위치에 따라 시작 행, 열 및 행과 열의 변화값 갱신
int findPosition(int n, int &row, int &col, int &r_temp, int &c_temp) {
	int size = pow(2, n);
	int position;
	if (r_temp >= size / 2) {
		if (c_temp >= size / 2) {
			position = 3;
			row += size / 2;
			col += size / 2;
			r_temp = r - row;
			c_temp = c - col;
		}
		else {
			position = 2;
			row += size / 2;
			r_temp = r - row;
		}
	}
	else {
		if (c_temp >= size / 2) {
			position = 1;
			col += size / 2;
			c_temp = c - col;
		}
		else {
			position = 0;
		}
	}
	return position;
}

//몇번째 방문인지 구하는 함수
//row, col: 시작 행, 열
//r_temp, c_temp: 사분면 내 상대적인 r, c 위치
//order: 사분면에서의 0행 0열의 방문 순서
void visitOrder(int n, int row, int col, int r_temp, int c_temp, int order) {
	if (n == 1) { //n이 1인 경우
		//r,c 위치에 해당하는 방문 순서 구하기
		ans = order + r_temp * 2 + c_temp * 1;
		return;
	}

	//r_temp, c_temp가 어느 사분면에 위치하는지(왼쪽 위 ~ 오른쪽 아래 순으로 0 ~ 3)
	int position = findPosition(n, row, col, r_temp, c_temp);

	//행렬 사이즈
	int size = pow(2, n);

	//r_temp, c_temp가 속한 사분면으로 축소
	visitOrder(n - 1, row, col, r_temp, c_temp, order + pow(size / 2, 2) * position);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	//입력
	cin >> n >> r >> c;
	
	//연산
	visitOrder(n, 0, 0, r, c, 0);

	//출력
	cout << ans << '\n';

}