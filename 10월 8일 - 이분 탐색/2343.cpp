#include <iostream>
#include <vector>

using namespace std;

vector<int> lecture;

//블루레이 크기가 size일 때 녹화할 수 있는 강의의 수
int howManyLectures(int size, int m) {
	int cnt = 0;
	int temp_size = size;
	for (int i = 0; i < lecture.size(); i++) {
		if (size < lecture[i])
			break;

		if (temp_size >= lecture[i]) {
			temp_size -= lecture[i];
			cnt++;
		}
		else {
			m--;
			if (m == 0)
				break;
			temp_size = size - lecture[i];
			cnt++;
		}
	}
	return cnt;
}

int lowerSize(int left, int right, int target, int num) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int count = howManyLectures(mid, num);

		if (count < target) { //녹화 가능한 강의 개수가 강의의 수보다 작으면 블루레이의 크기를 키워야 한다
			left = mid + 1;
		}
		else if (count >= target) { //녹화 가능한 강의 개수가 강의의 수보다 크거나 같으면 블루레이의 크기를 줄여본다.
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
	lecture.assign(n, 0);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		right = max(right, lecture[i]);
	}


	//연산 및 출력
	cout << lowerSize(1, right * n, n, m) << '\n';
}