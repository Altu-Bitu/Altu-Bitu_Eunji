#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> T;

//�־��� �ð� time�� �� �ɻ� ���� �� �ִ� ��� ��
long long howMany(long long time) {
	long long cnt = 0;
	for (int i = 0; i < T.size(); i++) 
			cnt += time / T[i];
	
	return cnt;
}


long long lowerTime(long long left, long long right, int target) {
	long long ans = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long people = howMany(mid); //mid ��ŭ�� �ð��� �־����� �� �ɻ� ���� ����� ��

		//�ɻ� ���� ����� ���� ����̿� ģ������ ������ ������
		//�ð��� �÷��� ��
		if (people < target) {
			left = mid + 1;
		}
		else if (people >= target) { //�ɻ� �޴� ����� ���� ����̿� ģ������ ������ ���ų� ������ �ð��� �� �ٿ�����
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
	T.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> T[i];

	//����
	sort(T.begin(), T.end());

	//���� �� ���
	cout << lowerTime(T[0], T[0] * m, m) << '\n';
}