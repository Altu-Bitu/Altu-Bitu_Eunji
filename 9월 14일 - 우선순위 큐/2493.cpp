#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<pair<int, int>> tops;

int receivingTop(int index, int height) {
	int result;
	while (!tops.empty()) {
		if (tops.top().second > height) { //������ top���� ������ ���� ž�� ���� �����
			result = tops.top().first;
			break;
		}
		tops.pop(); //���� ž �� ���� ž���� ���� ž�� ���ÿ��� ����
	}
	if (tops.empty())
		result = 0;
	//���� ž�� ��ġ�� ���̸� ���ÿ� �ִ´�.
	tops.push({ index, height });
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, height;
	vector<int> result;

	//�Է�
	cin >> n;
	result.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> height;
		result[i] = receivingTop(i + 1, height);
	}

	//���
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
}