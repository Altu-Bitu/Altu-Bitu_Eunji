#include <iostream>
#include <vector>

using namespace std;

long long minCost(int n, vector<int> cost, vector<int> length) {
	int temp_min = 1000000000; //지금까지 방문한 주유소 중 최소 리터 당 가격
	long long ans = 0;

	for (int i = 0; i < n - 1; i++) {
		temp_min = min(temp_min, cost[i]);
		ans += (long long)temp_min * length[i]; //지금까지 방문한 주유소 중 최소 가격을 가진 곳에서 가야할 거리만큼 주유함
	}

	return ans;
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<int> cost(n, 0);
	vector<int> length(n - 1, 0);

	for (int i = 0; i < n - 1; i++) 
		cin >> length[i];
	
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	//연산 + 출력
	cout << minCost(n, cost, length) << '\n';
}