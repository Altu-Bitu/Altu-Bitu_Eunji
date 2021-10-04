#include <iostream>
#include <vector>

using namespace std;

bool check[100001];

int minCount(int k, vector<int> coins) {
	int size = coins.size();
	vector<int> dp(k + 1, 10001);
	dp[0] = 0;
	for (int i = 0; i < size; i++) {
		//dp[j]: 0 ~ i 번째 동전 사용해서 j원을 만들었을 때 동전 개수의 최솟값
		for (int j = coins[i]; j <= k; j++) { 
			//원래 dp[j]와 j-coins[i]의 값에 현재 동전을 더해준 경우 비교해서 동전 개수의 최솟값 갱신
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == 10001) return -1;
	else return dp[k];
}

int main() {
	int n, k;

	//입력
	cin >> n >> k;
	vector<int> coins;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (!check[temp]) //중복을 체크하며 동전의 가치 저장
			coins.push_back(temp);
	}

	cout << minCount(k, coins) << '\n';
}