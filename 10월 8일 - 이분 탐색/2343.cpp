#include <iostream>
#include <vector>

using namespace std;

vector<int> lecture;

//��緹�� ũ�Ⱑ size�� �� ��ȭ�� �� �ִ� ������ ��
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

		if (count < target) { //��ȭ ������ ���� ������ ������ ������ ������ ��緹���� ũ�⸦ Ű���� �Ѵ�
			left = mid + 1;
		}
		else if (count >= target) { //��ȭ ������ ���� ������ ������ ������ ũ�ų� ������ ��緹���� ũ�⸦ �ٿ�����.
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

	//�Է�
	cin >> n >> m;
	lecture.assign(n, 0);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		right = max(right, lecture[i]);
	}


	//���� �� ���
	cout << lowerSize(1, right * n, n, m) << '\n';
}