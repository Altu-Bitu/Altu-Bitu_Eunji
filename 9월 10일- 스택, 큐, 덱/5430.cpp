#include<iostream>
#include<deque>
#include<string>

using namespace std;

bool R=false; //주어진 배열이 뒤집히면 true 아니면 false
bool error=false;

deque<int> processP(string p, int n) {
	deque<int> dq;
	string input;

	cin >> input;

	//입력받은 배열에서 숫자만 덱에 담기
	while (dq.size() < n) {
		string temp = "";
		for (int i = 1; i < input.size(); i++) {
			if (input[i] >= '0' && input[i] <= '9')
				temp += input[i];
			if (input[i] == ']' || input[i] == ',') {
				dq.push_back(stoi(temp));
				temp = "";
			}
		}
	}

	//함수 수행
	R = false;
	error = false;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			if (R)
				R = false;
			else
				R = true;
		}
		if (p[i] == 'D') {
			if (dq.empty()) {
				error=true; //error의 경우 R에 0 대입 후 함수 수행 중단
				break;
			}
			if (R == 1)
				dq.pop_back();
			else
				dq.pop_front();
		}
	}

	return dq;
}

void printDeque(deque<int> dq, int R) {
	cout << '[';
	if (R == 1) {
		while (!dq.empty()) {
			cout << dq.back();
			dq.pop_back();
			if (!dq.empty())
				cout << ',';
		}

	}
	else {
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
			if (!dq.empty())
				cout << ',';
		}
	}
	cout << "]\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	string p;

	//입력 및 출력
	cin >> t;

	while (t--) {
		cin >> p >> n;
		deque<int>result = processP(p, n);
		
		if (error)
			cout << "error\n";
		else 
			printDeque(result, R);
	}
}