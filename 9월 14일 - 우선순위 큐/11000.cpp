#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int numOfClassroom(vector<pair<int, int>> time) {
	//�� ���ǽ� �� ������ �ð��� ������ �ּ���
	priority_queue<int, vector<int>, greater<>> pq;	

	pq.push(time[0].second);
	for (int i = 1; i < time.size(); i++) {
		if (pq.top() > time[i].first) { 
			//���� ������ �ð��� ���� ������ ���� �ð����� �ʴٸ� ���ο� ���ǽ� �ʿ�
			//���ο� ���ǽǿ��� ���ǰ� ������ �ð��� ����
			pq.push(time[i].second);
		}
		else {
			//���ǽ��� �߰������� �ʿ����� �ʴٸ� ������ �ð� ����
			pq.pop();
			pq.push(time[i].second);
		}
	}

	return pq.size(); //���ǽ� ����(�켱���� ť�� ũ��) ��ȯ
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, result;
	vector<pair<int, int>> time;

	//�Է�
	cin >> n;
	time.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}
	//���� �ð� �������� time ����
	sort(time.begin(), time.end());

	//����
	result = numOfClassroom(time);

	//���
	cout << result;
}