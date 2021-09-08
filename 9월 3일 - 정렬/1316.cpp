#include<iostream>

using namespace std;

bool groupChecker(string word) {
	bool group = true;
	for (int i = 1; i < word.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (word[j] != word[j + 1] && word[j] == word[i]) { //� ����(word[j])�� �̿��� ���ڰ� �ٸ��� �� ���Ŀ� �ش� ����(word[i])�� �ٽ� �����Ѵٸ�
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

	//�Է� �� üũ
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> word;
		bool is_group = groupChecker(word);
		if (is_group) cnt++;
	}

	// ��� ���
	cout << cnt;
	
}