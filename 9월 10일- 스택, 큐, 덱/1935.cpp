#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <double> operand(26);

double postFix(string input) {
	double tmp1, tmp2;
	double result = 0;
	stack<double> s;

	for (int i = 0; i < input.size(); i++) {
		switch(input[i]) {
		case '+':
			tmp2 = s.top();
			s.pop();
			tmp1 = s.top();
			s.pop();
			s.push(tmp1 + tmp2);
			break;
		case '-':
			tmp2 = s.top();
			s.pop();
			tmp1 = s.top();
			s.pop();
			s.push(tmp1 - tmp2);
			break;
		case '*':
			tmp2 = s.top();
			s.pop();
			tmp1 = s.top();
			s.pop();
			s.push(tmp1 * tmp2);
			break;
		case '/':
			tmp2 = s.top();
			s.pop();
			tmp1 = s.top();
			s.pop();
			s.push(tmp1 / tmp2);
			break;
		default:
			s.push(operand[input[i] -'A']);
		}
	}
	result = s.top();
	s.pop();

	return result;
}

int main() {
	int n;
	double result;
	string input;

	//입력 및 연산
	cin >> n >> input;
	for (int i = 0; i < n; i++) {
		cin >> operand[i];
	}
	result = postFix(input);

	cout << fixed;
	cout.precision(2);

	//출력
	cout << result << '\n';
}