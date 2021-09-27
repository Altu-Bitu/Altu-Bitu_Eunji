#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct question {
	string input;
	int strike, ball;
};

//각 자리수가 모두 다르고, 0이 들어가지 않은 경우에 true 반환
bool check(string &num) {
	if ((num[0] != '0' && num[1] != '0' && num[2] != '0') &&
		(num[0] != num[1] && num[0] != num[2] && num[1] != num[2]))
		return true;
	else return false;
}

int count(vector<question> &q, string &num) {
	//주어진 모든 조건 중 하나를 만족할 때마다 증가
	int cnt = 0;

	for (int j = 0; j < q.size(); j++) {
		int num_strike = 0, num_ball = 0;
		for (int k = 0; k < 3; k++) {
			//해당 수(num[k])가 input에 들어있으며 같은 자리일 때
			if (num[k] == q[j].input[k])
				num_strike++;
			//해당 수(num[k])가 input에 들어있으나 다른 자리일 때
			if (num[k] == q[j].input[(k + 1) % 3] || num[k] == q[j].input[(k + 2) % 3])
				num_ball++;
		}
		//조건 하나를 만족하므로 cnt 증가
		if (q[j].strike == num_strike && q[j].ball == num_ball)
			cnt++;
	}

	return cnt;
}

int guessing(vector<question> q) {
	int result = 0;

	//123부터 987까지 모두 조건을 만족하는지 검사
	for (int i = 123; i <= 987; i++) {
		string num = to_string(i);

		//각 자리수가 모두 다르고, 0이 들어가지 않은 경우에만 조건에 부합하는지 검사
		if (check(num)) {
			
			//num(i)이 q의 input 및 조건에 만족한 횟수
			int cnt = count(q, num);
			
			//i가 주어진 모든 조건을 만족하는 수라면
			if (cnt == q.size())
				result++;
		}

	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<question> q;
	
	cin >> n;
	q.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> q[i].input >> q[i].strike >> q[i].ball;
	}

	int ans = guessing(q);

	cout << ans << '\n';
}