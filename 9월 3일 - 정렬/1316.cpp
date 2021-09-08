#include<iostream>

using namespace std;

bool groupChecker(string word) {
	bool group = true;
	for (int i = 1; i < word.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (word[j] != word[j + 1] && word[j] == word[i]) { //어떤 문자(word[j])와 이웃한 문자가 다르고 그 이후에 해당 문자(word[i])가 다시 등장한다면
				group = false;
				break;
			}
		}
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