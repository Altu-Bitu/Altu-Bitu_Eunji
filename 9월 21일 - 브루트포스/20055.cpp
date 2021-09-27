#include <iostream>
#include <vector>
using namespace std;

void rotation(int& start, int& end, int& size, vector<bool> &check) {
	//벨트 한 칸 회전
	start--;
	end--;
	if (start < 0) start += size;
	if (end < 0) end += size;

	//내리는 위치에 도달한 로봇 내리기
	if (check[end]) check[end] = false;
}

int cycle(vector<int> A, int k) {
	int size = A.size();
	int start = 0;
	int end = size / 2 - 1;
	int cnt = 0;

	//칸 위에 로봇이 있는지 나타내는 배열
	vector<bool> check(size, false);

	while (k > 0) {
		//단계 증가
		cnt++;

		//벨트 회전(올리는 위치와 내리는 위치의 인덱스 변경)
		rotation(start, end, size, check);

		//로봇 한 칸 이동
		for (int i = end - 1; ; i--) {
			int current_pos, next_pos;

			//현재 움직일 로봇 위치
			if (i < 0)
				current_pos = i + size;
			else
				current_pos = i;

			//내리는 위치 바로 전부터 시작하여 올리는 위치 방향으로 이동하며 로봇이 움직일 수 있는지 검사 후
			//올리는 위치에 오면 종료
			if (current_pos == start)
				break;

			//로봇이 이동할 다음 칸의 위치
			if (current_pos + 1 >= size)
				next_pos = current_pos + 1 - size;
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