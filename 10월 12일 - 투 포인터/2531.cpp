#include <iostream>
#include <vector>
#include <map>

using namespace std;

//�ʹ� �������� �ִ� ����ϴ� �Լ�
int maxCount(int k, int n, int c, vector<int>plates) {
	int ans = 0; //�������� �ִ�
	map<int, int> type; //�ʹ� ���� �� ���� ����
	type[c] = 1; //�ʱ�ȭ(���� ��ȣ�� �ش��ϴ� �ʹ��� ī��Ʈ���� �ʵ���)
	int temp = 0; //left ~ right �������� �ʹ��� ������

	for (int i = 0; i < k; i++) {
		type[plates[i]]++;
		if (type[plates[i]] == 1)
			temp++; //���� ����
	}
	ans = temp;

	int left = 0, right = k; //k���� �������� ������ ���� ����Ű�� ������(left), ������ �߰��� ���� ����Ű�� ������(right)
	while (left < n - 1) {
		type[plates[left]]--; //���� �� �� �ʹ� ���� �ϳ� ����
		if (type[plates[left]] == 0) { //������ �ʹ� ������ k�� ������ ���ٸ�
			temp--; //���� ����
			type.erase(plates[left]);
		}

		type[plates[right]]++; //�ش� ������ �ش��ϴ� �ʹ��� ���� ����
		if (type[plates[right]] == 1) // k���� ���� ���� ���� �������
			temp++; //���� ����
		ans = max(ans, temp); //�ִ� ����

		left++; //left, right ������ �ϳ��� ����
		right = (right + 1) % n;
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