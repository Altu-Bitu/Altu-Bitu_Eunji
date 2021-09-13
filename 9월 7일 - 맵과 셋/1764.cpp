#include<iostream>
#include<set>

using namespace std;

set<string> unknown(set<string> unknown1, int n) {
	string unknown2;
	set<string> result;
	while (n--) {
		cin >> unknown2;
		if (unknown1.find(unknown2) != unknown1.end())
			result.insert(unknown2);
	}
	return result;
}

int main() {
	int n, m;
	string input;
	set<string>unknown1;
	set<string>result;

	//입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		unknown1.insert(input);
	}


	result = unknown(unknown1, m);

	//출력
	cout << result.size() << '\n';
	for (auto iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << '\n';
	}

}