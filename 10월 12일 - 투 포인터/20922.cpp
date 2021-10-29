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
	while (left <= right && right < n - 1) {
		right++; //���� �ø�
		count[numbers[right]]++; //������ �����Ͱ� ����Ű�� ������ Ƚ�� �ϳ� �ø�
		temp++; //���� ������ ���� 1 ����

		if (count[numbers[right]] > k) { //���� ������ �����Ͱ� ����Ű�� ������ Ƚ���� k���� ũ�ٸ�
			count[numbers[right]]--; //���� ������ �����Ͱ� ����Ű�� �ִ� ����(������ �����Ϳ� �ߺ�)�� Ƚ�� �ϳ� ����
			while (left <= right) { //���� �����Ͱ� ������ �����ͺ��� ���� ������ ���� ����
				if (numbers[left] == numbers[right]) { //������ �����Ͱ� ����Ű�� ���ҿ� ���� �����Ͱ� ����Ű�� ���Ұ� ������
					left++; //���� ������ ���� ��
					temp--; //���� ���� ��
					break; // �ݺ��� Ż��
				}

				//������ �����Ϳ� ���� �����Ͱ� ����Ű�� ���Ұ� �ٸ��ٸ�
				count[numbers[left]]--; //���Ұ� ���� Ƚ�� ����
				left++; //���� ������ ����
				temp--; //���� ������ ���� ����
			}
		}
		ans = max(ans, temp); //���� ���� ����
	}

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