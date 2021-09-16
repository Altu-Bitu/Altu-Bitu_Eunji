#include<iostream>
#include<deque>

using namespace std;

int main() {
	deque<int> d;
	int n, k;
	string cmd;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> k;
			d.push_front(k);
			continue;
		}
		if (cmd == "push_back") {
			cin >> k;
			d.push_back(k);
			continue;
		}
		if (cmd == "pop_front") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
			continue;
		}
		if (cmd == "pop_back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
			continue;
		}
		if (cmd == "size") {
			cout << d.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << d.empty() << '\n';
			continue;
		}
		if (cmd == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
			continue;
		}
		if (cmd == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
			continue;
		}
	}
}