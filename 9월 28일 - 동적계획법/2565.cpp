#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minRemoval(int n, vector<pair<int,int>>lines) {
	int cnt = 0;
	//A 전봇대의 위치가 오름차순으로 정렬되어 있으므로
	//B 전봇대에서의 위치도 오름차순으로 정렬되면 교차하지 않는다.
	//dp에는 각 전깃줄에서 해당 전깃줄과 교차되지 않는 전깃줄의 수를 저장한다.
	//즉, 자신을 포함해서 설치할 수 있는 전깃줄의 최대 개수를 저장.

	vector<int>dp(n, 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (lines[i].second > lines[j].second && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		cnt = max(cnt, dp[i]);
	}
	for (int i = 0; i < n; i++)
		cout << "dp: " << dp[i] << '\n';
	return n - cnt; //오름차순으로 정렬되지 않은 전깃줄만 빼면 된다.
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<pair<int, int>>lines(n, { 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first >> lines[i].second;
	}
	//A전봇대 기준으로 오름차순 정렬
	sort(lines.begin(), lines.end());

	//출력
	cout << minRemoval(n, lines) << '\n';
}