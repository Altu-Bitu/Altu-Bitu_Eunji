#include<iostream>
#include<map>
#include<vector>
#include <algorithm>

using namespace std;

map<string, int> note; //단어와 나온 횟수 저장할 map

bool compare(string i1, string i2) {
	if (note[i1] != note[i2])
		return note[i1] > note[i2];
	if (i1.size() != i2.size())
		return i1.size() > i2.size();
	else
		return i1 < i2;
}

vector<string> sortNote(map<string, int> note) {
	vector<string> temp;

	//note의 단어들을 temp로 옮김
	for (auto iter = note.begin(); iter != note.end(); iter++) {
		temp.push_back({ iter-> first });
	}
	//조건에 맞게 정렬
	sort(temp.begin(), temp.end(), compare);

	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	string input;
	vector<string>note_result;

	//입력
	cin >> n >> m;
	while (n--) {
		cin >> input;
		if (input.size() >= m) 
			note[input] += 1;
	}

	//출력
	note_result = sortNote(note);
	for (int i = 0; i < note_result.size(); i++)
		cout << note_result[i] << '\n';

}