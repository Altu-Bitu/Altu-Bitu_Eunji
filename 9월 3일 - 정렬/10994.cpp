#include<iostream>
#include<vector>

using namespace std;

void drawStar(int n, int row_start, int col_start, vector<vector<string>>& paper) {
	int width = 4 * n - 3;
	for (int i = row_start; i < width + row_start; i++) {
		for (int j = col_start; j < width + row_start; j++) {
			if (i == row_start || i == row_start + width -1 || j == col_start || j == col_start + width - 1)
				paper[i][j] = "*";
			else
				paper[i][j] = " ";
		}
	}
	if (width >= 1)
		drawStar(n - 1, row_start+2, col_start+2,  paper);
}

int main() {
	int n, width;
	vector<vector<string>> paper;

	//입력
	cin >> n;
	width = width = 4 * n - 3;
	paper.assign(width, vector<string>(width, " "));

	//그리기
	drawStar(n, 0, 0, paper);

	//출력
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			cout << paper[i][j];
		}
		cout << "\n";
	}

}