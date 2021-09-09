#include<iostream>
#include<vector>

using namespace std;

bool groupChecker(string word) {
	bool group = true;
	vector<bool>letter;
	letter.assign(26, false);
	letter[word[0] - 'a'] = true;

	for (int i = 1; i < word.length(); i++) {
		if (word[i] != word[i-1] && letter[word[i] - 'a']) {
			group = false;
			return group;
		}
		if (word[i] != word[i - 1])
			letter[word[i] - 'a'] = true;
	}
	return group;
}

int main() {
	int n, cnt = 0;
	string word;

	//입력 및 체크
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> word;
		bool is_group = groupChecker(word);
		if (is_group) cnt++;
	}

	// 결과 출력
	cout << cnt;
	
}