#include <iostream>
#include <vector>
#include <map>

using namespace std;

//���� ���� ������ ���� ���ϴ� �Լ�
int maxLength(int n, int k, vector<int> numbers) {
	int ans = 1; //���� ���� ������ ����
	int left = 0, right = 0;
	map<int, int> count; //���Ұ� ���� Ƚ�� �����ϴ� ����
	count[numbers[left]]++; //�ʱ�ȭ
	int temp = 1; //������� ������ ���� ����
	while (right < n - 1) {
		while (right < n - 1 && count[numbers[right]] <= k) { //������ Ƚ���� k ������ ���
			right++; //������ ������ �����ϸ� ���� ����
			count[numbers[right]]++; //������ ������ �����Ͱ� ����Ű�� ������ Ƚ�� ����
			temp++; //������ ���� ����
		}

		ans = max(ans, temp - 1); //���� ���� ����
		while (left <= right && count[numbers[right]] > k) { //������ Ƚ���� k�� �ʰ��� ���
			count[numbers[left]]--; //���� �����Ͱ� ����Ű�� ������ Ƚ�� ���� ��
			left++; //���� ������ ����
			temp--; //������ ���� ����
		}
	}
	ans = max(ans, temp); //���� ���� ����
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	//�Է�
	cin >> n >> k;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	//���� �� ���
	cout << maxLength(n, k, numbers) << '\n';
}