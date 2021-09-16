#include<iostream>
#include<stack>
using namespace std;

string toPostFix(string input) {
	stack<char> s;
	string result="";

	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '(':
			s.push(input[i]);
			break;
		case '*': case '/':
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				result += s.top();
				s.pop();
			}
			s.push(input[i]);
			break;
		case '+': case'-':
			while (!s.empty() && s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.push(input[i]);
			break;
		case ')':
			while (s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop(); // '(' pop
			break;
		default:
			result += input[i];
			break;
		}

	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input,result;

	//입력
	cin >> input;

	//연산
	result = toPostFix(input);

	//출력
	cout << result << '\n';
}