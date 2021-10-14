#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

//������ ������ �ִ��� �ּڰ��� mid �� �� ������ ����
int countSection(int mid) {
	int cnt = 1; //������ ������ 1�� �̻��̹Ƿ�
	int min_score = arr[0], max_score = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		min_score = min(min_score, arr[i]);
		max_score = max(max_score, arr[i]);

		if (max_score - min_score > mid) {
			cnt++;
			min_score = arr[i];
			max_score = arr[i];
		}
	}
	return cnt;
}

//������ ������ �ִ��� �ּڰ��� ���ϴ� �Լ�
int minOfMaxSectionScore(int left, int right, int m) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = countSection(mid); //������ ����
		if (cnt <= m) { //������ ������ m ���϶�� �ִ��� �ּڰ��� �� �ٿ�����
			ans = mid;
			right = mid - 1;
		}
		else if (cnt > m) {//������ ������ m�� �ʰ��ϸ� �ִ��� �ּڰ��� �� �÷��� �Ѵ�.
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	//�Է�
	cin >> n >> m;
	arr.assign(n, 0);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(arr[i], right);
	}

	//���� �� ���
	cout << minOfMaxSectionScore(0, right, m) << '\n';
}