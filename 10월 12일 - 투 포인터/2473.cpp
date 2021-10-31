#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��� �ϳ��� ���� �� �ٸ� �� ��� �̿��� 0�� ������ ȥ��
vector<int> liquid(vector<int> arr, int num, int idx) {
	vector<int> ans(3, 0);
	long long min_diff = 3 * 1e9 + 1;

	int left = idx + 1, right = arr.size() - 1;
	ans[0] = num;

	while (left < right) {
		long long mix = (long long) num +  arr[left] + arr[right]; //�� ��� ȥ��
		if (mix == 0) { // ȥ�յ� ���� 0�̶�� �ٷ� ��ȯ
			ans[1] = arr[left], ans[2] = arr[right];
			return ans;
		}
		if (abs(mix) < min_diff) { //0�� ����� ���� ������ �� �ִ��� Ȯ��
			min_diff = abs(mix);
			ans[1] = arr[left], ans[2] = arr[right];
		}

		if (mix > 0)// 0���� ũ�� right ������ �������� �̵�
			right--;
		else if (mix < 0) // 0���� ������ left ������ ���������� �̵�
			left++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	//�Է�
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//����
	sort(arr.begin(), arr.end());

	//����
	vector<int> temp;
	vector<int> ans;
	long long sum_ans = 3 * 1e9 + 1, sum_temp = 0;

	for (int i = 0; i < n - 2; i++) {
		//arr[i]: ������ ���
		temp = liquid(arr, arr[i], i);

		for (int i = 0; i < 3; i++)
			sum_temp +=  temp[i]; //�� ����� Ư������ ��

		if (abs(sum_temp) < abs(sum_ans)) { //������ ���� �պ��� 0�� �����ٸ� ���� ����
			ans = temp;
			sum_ans = sum_temp;
		}
		sum_temp = 0;
	}
	sort(ans.begin(), ans.end()); //�� ����

	//���
	for (int i = 0; i < 3; i++)
		cout << ans[i] << ' ';
}