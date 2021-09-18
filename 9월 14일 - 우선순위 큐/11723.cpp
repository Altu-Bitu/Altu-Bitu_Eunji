#include <iostream>
#include <vector>

using namespace std;

void add(vector<int> &s, int x) {
	s[x-1] = 1;
}

void remove(vector<int> &s, int x) {
	s[x-1] = 0;
}

int check(vector<int> &s, int x) {
	if (s[x-1]) return 1;
	else return 0;
}

void toggle(vector<int> &s, int x) {
	if (s[x-1])
		s[x-1] = 0;
	else
		s[x-1] = 1;
}

void all(vector<int> &s) {
	for (int i = 0; i < 20; i++) {
		s[i] = 1;
	}
}

void empty(vector<int> &s) {
	for (int i = 0; i < 20; i++) {
		if (s[i] == 1)
			s[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, x;
	string cmd;

	//집합 S: 원소 x가 있다면 인덱스 x-1에 있는 값이 1
	vector<int> s(21);

	
	cin >> m;
	while (m--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			add(s, x);
			continue;
		}
		if (cmd == "remove") {
			cin >> x;
			remove(s, x);
			continue;
		}
		if (cmd == "check") {
			cin >> x;
			cout << check(s, x) << '\n';
			continue;
		}
		if (cmd == "toggle") {
			cin >> x;
			toggle(s, x);
			continue;
		}
		if (cmd == "all") {
			all(s);
			continue;
		}
		if (cmd == "empty") {
			empty(s);
		}
	}
}