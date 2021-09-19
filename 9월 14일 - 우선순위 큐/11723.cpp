#include <iostream>
#include <vector>

using namespace std;

void add(vector<bool> &s, int x) {
	s[x-1] = true;
}

void remove(vector<bool> &s, int x) {
	s[x-1] = false;
}

int check(vector<bool> &s, int x) {
	return s[x - 1];
}

void toggle(vector<bool> &s, int x) {
	if (s[x-1])
		s[x-1] = false;
	else
		s[x-1] = true;
}

void all(vector<bool> &s) {
	for (int i = 0; i < 20; i++) {
		s[i] = true;
	}
}

void empty(vector<bool> &s) {
	for (int i = 0; i < 20; i++) {
		if (s[i])
			s[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, x;
	string cmd;

	//���� S: ���� x�� �ִٸ� �ε��� x-1�� �ִ� ���� true
	vector<bool> s(21);

	
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