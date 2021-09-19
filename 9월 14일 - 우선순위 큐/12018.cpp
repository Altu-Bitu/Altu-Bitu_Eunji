#include<iostream>
#include<queue>
using namespace std;

//����� ��� ���� �ʿ��� �ּ����� ���ϸ���
int mileageNeeded(int P, int L, vector<int> mileage_p){
	//ũ�⸦ �����ο�(L)�� �����ϸ� ������� ���� ���ϸ����� ������ �ּ���
	priority_queue<int, vector<int>, greater<>> pq;

	if (P < L) return 1;

	for (int i = 0; i < P; i++) {
		if (pq.size() < L)
			pq.push(mileage_p[i]);
		else {
			if (pq.top() < mileage_p[i]) {
				pq.pop();
				pq.push(mileage_p[i]);
			}
		}
	}

	return pq.top();
	
}

//���� �� �ִ� ���� ����
int numOfCourses(int m, priority_queue<int, vector<int>, greater<>> pq) {
	int result = 0;
	while (!pq.empty() && m >= pq.top()) {
			m -= pq.top();
			pq.pop();
			result++;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, input_m;
	int P, L; //��û�� ��� ��, �����ο�
	vector<int> mileage_p; //��û�� ������� ���� ���ϸ��� ������ �迭
	int result;
	//�� ������ ��µ� �ʿ��� �ּ����� ���ϸ����� ������ �ּ���
	priority_queue<int, vector<int>, greater<>> mileage;

	//�Է� �� ����
	cin >> n >> m;

	while (n--) {
		cin >> P >> L;
		mileage_p.assign(P, 0);
		for(int i=0; i<P; i++) {
			cin >> mileage_p[i];
		}
		mileage.push(mileageNeeded(P, L, mileage_p));
	}

	result = numOfCourses(m, mileage);

	//���
	cout << result << '\n';
}