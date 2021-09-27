#include <iostream>

using namespace std;

int getLength(int r, int b) {
	int area = r + b;
	int length = 1;

	for (int i = area; i >= 3; i--) {
		//넓이가 i로 나누어떨어지고 방의 테두리가 빨간색 타일로 딱 맞춰서 채워지는 경우
		if (area % i == 0 && i * 2 + (area / i - 2) * 2 == r) {
			length = i;
			break;
		}	
	}
	return length;
}

int main() {
	int r, b;
	int length, width;

	//입력
	cin >> r >> b;

	//연산
	length = getLength(r, b);
	width = (r + b) / length;

	//출력
	cout << length << " " << width << '\n';
}