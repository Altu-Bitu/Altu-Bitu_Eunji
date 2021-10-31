#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� ������ �ƴ��� ��ȯ�ϴ� �Լ�
bool isGood(int idx, int num, vector<int>numbers) {
	int left = 0, right = numbers.size() - 1;

	while (left < right) {
		if (left == idx) { //���� �����Ͱ� num�� �ε����� ���ٸ�
			left++;
			continue;
		}
		if (right == idx) { //������ �����Ͱ� num�� �ε����� ���ٸ�
			right--;
			continue;
		}

		int sum = numbers[left] + numbers[right];

		if (sum == num) //left, right�� ����Ű�� ������ ���� num�� �ȴٸ� true ��ȯ
			return true;
		else if (sum < num)  //���� num���� �۴ٸ� left ������ ���������� �̵�
			left++;
		else //���� num���� ũ�ٸ� right ������ �������� �̵�
			right--;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	//�Է�
	cin >> n;
	vector<int>numbers(n, 0);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	//����
	sort(numbers.begin(), numbers.end());

	//���� �� ���
	int ans = 0;
	if (n >= 3) {
		for (int i = 0; i < n; i++) {
			if (isGood(i, numbers[i], numbers))
				ans++;
		}
	}
	cout << ans << '\n';	
}