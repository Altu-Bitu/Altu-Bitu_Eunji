#include<iostream>
#include<set>

using namespace std;

int isIn(int m, set<string> s) {
	int result = 0;
	string input;

	while (m--) {
		cin >> input;
		if (s.find(input) != s.end())
			result++;
	}
	return result;
}

int main() {
	int n, m, result = 0;
	string input;
	set<string> s; //���� s
	
	//�Է�
	cin >> n >> m;
	while (n--) {
		cin >> input;
		s.insert(input);
	}
		
	result = isIn(m, s);

	//���
	cout << result;
}