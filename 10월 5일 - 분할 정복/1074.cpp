#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int r, c;
int ans;


//몇사분면에 속하는지
int findPosition(int n, int r_temp, int c_temp) {
	int size = pow(2, n);
	int position;
	if (r_temp >= size / 2) {
		if (c_temp >= size / 2)
			position = 4;
		else
			position = 3;
	}
	else {
		if (c_temp >= size / 2)
			position = 1;
		else
			position = 2;
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

	//r_temp, c_temp가 어느 사분면에 위치하는지
	int position = findPosition(n, r_temp, c_temp);
	//행렬 사이즈
	int size = pow(2, n);
	switch (position) {
	case 1: //1사분면에 위치한 경우
		col += size / 2;
		c_temp = c - col;
		order += pow(size / 2, 2);
		visitOrder(n - 1, row, col, r_temp, c_temp, order);
		break;
	case 2: //2사분면에 위치한 경우
		visitOrder(n - 1, row, col, r_temp, c_temp, order);
		break;
	case 3: //3사분면에 위치한 경우
		row += size / 2;
		r_temp = r - row;
		order += pow(size / 2, 2) * 2;
		visitOrder(n - 1, row, col, r_temp, c_temp, order);
		break;
	case 4: //4사분면에 위치한 경우
		row += size / 2;
		col += size / 2;
		r_temp = r - row;
		c_temp = c - col;
		order += pow(size / 2, 2) * 3;
		visitOrder(n - 1, row, col, r_temp, c_temp, order);
		break;
	}
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