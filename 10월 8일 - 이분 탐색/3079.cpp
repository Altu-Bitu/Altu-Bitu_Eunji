#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> T;

//주어진 시간 time일 때 심사 받을 수 있는 사람 수
long long howMany(long long time) {
	long long cnt = 0;
	for (int i = 0; i < T.size(); i++) 
			cnt += time / T[i];
	
	return cnt;
}


long long lowerTime(long long left, long long right, int target) {
	long long ans = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long people = howMany(mid); //mid 만큼의 시간이 주어졌을 때 심사 받은 사람의 수

		//심사 받은 사람의 수가 상근이와 친구들의 수보다 적으면
		//시간을 늘려야 함
		if (people < target) {
			left = mid + 1;
		}
		else if (people >= target) { //심사 받는 사람의 수가 상근이와 친구들의 수보다 많거나 같으면 시간을 더 줄여본다
			ans = mid;
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	//입력
	cin >> n >> m;
	T.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> T[i];

	//정렬
	sort(T.begin(), T.end());

	//연산 및 출력
	cout << lowerTime(T[0], T[0] * m, m) << '\n';
}