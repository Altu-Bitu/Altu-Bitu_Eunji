#include<iostream>

using namespace std;

int main() {
	int n;
	int width;

	//입력
	cin >> n;
	width = 4 * n - 3;


	//처음 절반
	for (int i = 1; i <= width; i++) {
		if (i % 2 == 0) //짝수번째 행은 공백
			cout << "\n";
		else if (i % 4 == 1) {
			for (int j = 0; j < (i - 1) / 4; j++) {
				cout << "* ";
			}
			for (int j = 0; j < width - (i - 1); j++) {
				cout << "*";
			}
			for (int j = 0; j < (i - 1) / 4; j++) {
				cout << " *";
			}
		}
		else { // i%4 ==3
			for (int j = 0; j < (i + 1) / 4; j++) {
				cout << "* ";
			}
			for (int j = 0; j < width - (i + 1); j++) {
				cout << " ";
			}
			for (int j = 0; j < (i + 1) / 4; j++) {
				cout << " *";
			}
		}

	}
	
	
	//나머지 반
	for (int i = width-1; i >= 1; i--) {
		if (i % 2 == 0)
			cout << "\n";
		else if (i % 4 == 1) {
			for (int j = 0; j < (i - 1) / 4; j++) {
				cout << "* ";
			}
			for (int j = 0; j < width - (i - 1); j++) {
				cout << "*";
			}
			for (int j = 0; j < (i - 1) / 4; j++) {
				cout << " *";
			}
		}
		else {
			for (int j = 0; j < (i + 1) / 4; j++) {
				cout << "* ";
			}
			for (int j = 0; j < width - (i + 1); j++) {
				cout << " ";
			}
			for (int j = 0; j < (i + 1) / 4; j++) {
				cout << " *";
			}
		}

	}

}