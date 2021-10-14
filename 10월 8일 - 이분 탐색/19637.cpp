#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int>power;

//칭호 매칭하는 함수
vector<string> findName(int m, map<int, string> name) {
	vector<string> names;
	for (int i = 0; i < m; i++) {
		//power[i] 이상인 수가 처음으로 나오는 위치 반환
		//upper bound의 경우 경계 값이 입력될 경우 한단계 높은 칭호 매칭됨
		auto iter = name.lower_bound(power[i]); 
		names.push_back(iter->second);
	}
	
	return names;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	map<int, string> name;

	//입력
	cin >> n >> m;
	power.assign(m, 0);

	for (int i = 0; i < n; i++) {
		string value;
		int key;
		cin >> value >> key;
		if (name[key] == "")
			name[key] = value;
	}

	for (int i = 0; i < m; i++)
		cin >> power[i];

	//연산
	vector<string> names = findName(m, name);

	//출력
	for (int i = 0; i < m; i++)
		cout << names[i] << '\n';
}