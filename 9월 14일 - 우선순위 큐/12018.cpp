#include<iostream>
#include<queue>
using namespace std;

//����� ��� ���� �ʿ��� �ּ����� ���ϸ���
int mileageNeeded(int P, int L){
	//�� ����� ���� ���ϸ����� �Է¹޾� ������ ����
	int input_m;
	//ũ�⸦ �����ο�(L)�� �����ϸ� ������� ���� ���ϸ����� ������ �ּ���
	priority_queue<int, vector<int>, greater<>> pq;

	//�����ο����� ��û�ο��� ���� ���
	if (P < L) {
		while (P--)
			cin >> input_m;
		return 1;
	}

	for (int i = 0; i < P; i++) {
		cin >> input_m;
		if (pq.size() < L)
			pq.push(input_m);
		else {
			if (pq.top() < input_m) {
				pq.pop();
				pq.push(input_m);
			}
		}
	}

	return pq.top();
	
}

//���� �� �ִ� ���� ����
int numOfCourses(int m, priority_queue<int, vector<int>, greater<>> pq) {
	int result = 0;
	while (!pq.empty()) {
		if (m >= pq.top()) {
			m -= pq.top();
			pq.pop();
			result++;
		}
		else
			break;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int P, L; //��û�� ��� ��, �����ο�
	int result;
	//�� ������ ��µ� �ʿ��� �ּ����� ���ϸ����� ������ �ּ���
	priority_queue<int, vector<int>, greater<>> mileage;

	//�Է� �� ����
	cin >> n >> m;

	while (n--) {
		cin >> P >> L;
		mileage.push(mileageNeeded(P, L));
	}

	result = numOfCourses(m, mileage);

	//���
	cout << result << '\n';
}