#include<iostream>
#include<set>

using namespace std;

set<string> unknown(set<string> unknown1, set<string> unknown2) {
	set<string> result;

	for (auto iter = unknown1.begin(); iter != unknown1.end(); ++iter) {
		if (unknown2.find(*iter) != unknown2.end())
			result.insert(*iter);
	}

	return result;
}

int main() {
	int n, m;
	string input;
	set<string>unknown1;
	set<string>unknown2;
	set<string>result;

	//입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		unknown1.insert(input);
	}

	for (int i = 0; i < m; i++) {
		cin >> input;
		unknown2.insert(input);
	}

	result = unknown(unknown1, unknown2);

	//출력
	cout << result.size() << '\n';
	for (auto iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << '\n';
	}

}