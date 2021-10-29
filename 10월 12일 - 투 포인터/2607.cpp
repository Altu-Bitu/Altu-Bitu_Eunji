#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int similarCount(int n, vector<string> words) {
	int ans = 0;
	string first = words[0]; //첫번째 단어
	int length_first = words[0].size(); //첫번째 단어의 길이 
	
	map<char, int> construction_first; //첫번째 단어에 들어있는 문자의 개수 저장
	vector<bool> check(26, false); //첫번째 단어에 들어있는 문자인지 체크하기 위한 배열
	for (int i = 0; i < length_first; i++) {
		construction_first[first[i]]++;
		check[first[i] - 'A'] = true;
	}

	for (int i = 1; i < n; i++) {
		string temp = words[i]; //비교할 단어
		int length_temp = words[i].size(); //첫번째 단어와 비교할 단어의 길이

		if (abs(length_temp - length_first) > 1) //단어 길이의 차이가 1보다 크면 비슷한 단어가 아님
			continue;

		map<char, int> construction_temp = construction_first; //첫번째 단어의 구성 복사
		int different = 0; //두 단어의 차이

		//비슷한 단어인지 검사
		if (length_temp < length_first) { //단어의 길이가 더 짧은 경우 -> 문자 추가만 가능
			for (int j = 0; j < length_temp; j++) {
				//첫번째 단어에 없는 문자이거나 존재하는 문자이나 개수가 더 많은 경우 -> 교체, 삭제 필요
				if (!check[temp[j] - 'A'] || (check[temp[j] - 'A'] && construction_temp[temp[j]] == 0)) { 
					different = 2;
					break;
				}
				//해당 문자 존재하며 아직 개수가 0보다 큼 -> 하나 감소
				construction_temp[temp[j]]--;
			}
		}
		else { //단어의 길이가 길거나 같은 경우
			for (int j = 0; j < length_temp; j++) {
				//첫번째 단어에 해당 문자가 존재할 경우 -> 개수 하나씩 감소 시키며 체크
				if (check[temp[j] - 'A']) {
					if (construction_temp[temp[j]] > 0) //문자 개수가 0보다 큼
						construction_temp[temp[j]]--; //개수 하나 감소
					else if (construction_temp[temp[j]] == 0) { //첫번째 단어에 존재하는 문자이나 개수가 더 많음
						different++; //차이 증가
					}
				}
				else //첫번째 단어에 존재하지 않는 문자의 경우(교체 or 삭제)
					different++;

				//차이가 2개 이상이면 같은 구성으로 바꿀 수 없음(비슷한 단어가 아님)
				if (different >= 2)
					break;
			}
		}
		
		if (different <= 1) { //비슷한 단어이면
			ans++;
			different = 0;
		}
	}
	return ans;
}

int main() {
	int n;
	string word;

	//입력
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];

	//연산 및 출력
	cout << similarCount(n, words) << '\n';
}