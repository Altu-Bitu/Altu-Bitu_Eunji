#include <iostream>
#include <vector>
using namespace std;

int cycle(vector<int> A, int k) {
	int start = 0;
	int end = A.size() / 2 - 1;
	int cnt = 0;

	//칸 위에 로봇이 있는지 나타내는 배열
	vector<bool> check(A.size(), false);

	while (k > 0) {
		//단계 증가
		cnt++;

		//벨트 한 칸 회전
		start--;
		end--;
		if (start < 0) start += A.size();
		if (end < 0) end += A.size();
		
		//내리는 위치에 도달한 로봇 내리기
		if (check[end]) check[end] = false;

		//로봇 한 칸 이동
		for (int i = A.size() / 2 - 2; i >= 1  ; i--) {
			int current_pos, next_pos;

			//현재 움직일 로봇 위치
			if (start + i >= A.size()) 
				current_pos = start + i - A.size();
			else 
				current_pos = start + i;

			//로봇이 이동할 다음 칸의 위치
			if (current_pos + 1 >= A.size())
				next_pos = current_pos + 1 - A.size();
			else
				next_pos = current_pos + 1;
			

			if (check[current_pos] && !check[next_pos] && A[next_pos]) {
				check[current_pos] = false;
				check[next_pos] = true;
				A[next_pos]--;

				//내구도가 0이 되었다면
				if (A[next_pos] == 0)
					k--;

				//다음 칸은 움직일 필요 없음.
				i++;
			}
		}

		//내리는 위치에 도달한 로봇이 있다면 내리기
		if (check[end]) check[end] = false;

		//로봇을 올리고 해당 위치의 내구도 감소시키기
		if (A[start]) {
			check[start] = true;
			A[start]--;

			if (A[start] == 0)
				k--;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	
	//입력
	cin >> n >> k;

	vector<int> A(2 * n, 0);
	for (int i = 0; i < A.size(); i++) {
		cin >> A[i];
	}

	//연산
	int ans = cycle(A, k);

	//출력
	cout << ans << '\n';
}