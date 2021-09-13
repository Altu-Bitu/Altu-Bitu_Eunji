#include<iostream>
#include<vector>
#include<map>

using namespace std;

void countSmaller(vector<int> x) {
	map<int, int> temp;

	for (int i = 0; i < x.size(); i++) { //입력받은 좌표들을 map의 key로 저장
		temp[x[i]] = 0;
	}

	int cnt = 0;
	for (auto iter = temp.begin(); iter != temp.end(); iter++) {
		iter->second = cnt++; //각 key보다 작은 key의 개수를 value에 저장
	}

	for (int i = 0; i < x.size(); i++)
		cout << temp[x[i]] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> x;
	map<int, int> result;

	//입력
	cin >> n;
	x.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	//출력
	countSmaller(x);
}