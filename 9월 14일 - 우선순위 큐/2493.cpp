#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<pair<int, int>> tops;

int receivingTop(int index, int height) {
	int result;
	while (!tops.empty()) {
		if (tops.top().second > height) { //스택의 top으로 갈수록 현재 탑과 제일 가까움
			result = tops.top().first;
			break;
		}
		tops.pop(); //왼쪽 탑 중 현재 탑보다 낮은 탑은 스택에서 제거
	}
	if (tops.empty())
		result = 0;
	//현재 탑의 위치와 높이를 스택에 넣는다.
	tops.push({ index, height });
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, height;
	vector<int> result;

	//입력
	cin >> n;
	result.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> height;
		result[i] = receivingTop(i + 1, height);
	}

	//출력
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
}