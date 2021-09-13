#include<iostream>
#include<map>

using namespace std;

int caseCount( map<string, int> clothes) {
	int result = 1;

	for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
		result *= (iter->second + 1);
	}
	
	return result - 1;
}

int main() {
	int m, n; //테스트 케이스 수, 의상 수
	string input_key;

	//입력 및 출력
	cin >> m;

	while (m--) {
		map<string, int> clothes;
		int result = 0;
		cin >> n;
		while(n--) {
			cin >> input_key >> input_key;
			if (clothes.find(input_key) != clothes.end())
				clothes[input_key] += 1;
			else 
				clothes[input_key] = 1;
		}
		result = caseCount(clothes);
		cout << result << '\n';
	}
}