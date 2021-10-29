#include <iostream>
#include <vector>
#include <map>

using namespace std;

//�ʹ� �������� �ִ� ����ϴ� �Լ�
int maxCount(int k, int n, int c, vector<int>plates) {
	int ans = 0; //����

	int left = 0, right = 0;
	map<int, int> type; //�ʹ� ���� �� ���� ����
	type[plates[left]]++; //�ʱ�ȭ
	int temp = 1; //left ~ right �������� �ʹ��� ������

	while (left < n) {
		right++; //���� �ø�
		if (right == n) // right�� ���� ���� �Ѿ�� ó�� ���ø� ����Ű����
			right = 0;
		type[plates[right]]++; //�ش� ������ �ش��ϴ� �ʹ��� ���� ����
		if (type[plates[right]] == 1 && plates[right] != c) // left ~ right ���� ���� ���� �����̰� ������ ���� �ʹ��� �ƴ϶��
			temp++; //���� ����


		// left ~ right ���� ������ ���� ������ k���̸�
		if ((right > left && right - left == k - 1) || (right < left && left - right == n - k + 1)) {
			ans = max(temp, ans); //ans ����
			//left �� ���� �� ó��
			type[plates[left]]--;
			if (type[plates[left]] == 0) {
				type.erase(plates[left]);
				if (plates[left] != c)
					temp--;
			}
			left++; //left ����
		}
	}
	return ans + 1; //�������� �޴� �ʹ� ���� �ϳ� ���ؼ� ��ȯ
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c;

	//�Է�
	cin >> n >> d >> k >> c;
	vector<int>plates(n);

	for (int i = 0; i < n; i++)
		cin >> plates[i];

	//���� �� ���
	cout << maxCount(k, n, c, plates) << '\n';
}