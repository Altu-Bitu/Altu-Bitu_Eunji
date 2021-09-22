#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfMoving(vector<pair<int, int>> melody) {
	int count = 0;
	int num = 7;

	//���� ���� ���� �ʰ� ���� �ٸ��� �հ��� �����ӿ� ������ ���� �����Ƿ� �ٸ��� �հ��� ������ count
	while (--num) {
		//� ������ ������ �ִ��� ������ �켱���� ť(�ִ���)
		priority_queue<int> pressed;
		for (int i = 0; i < melody.size(); i++) {
			//�ش� ���� �ƴϸ� pass
			if (melody[i].first != num)
				continue;
			
			//�켱���� ť�� ������� �ʰ� ����� ���� ���� ���� �������� �ϴ� �������� ���� ���̸�
			while (!pressed.empty() && pressed.top() > melody[i].second) {
				//���� ���� �� ���� �� count ����
				pressed.pop();
				count++;
			}
			//�켱���� ť�� ����ִٸ� �������� �ϴ� ���� ����
			if (pressed.empty()) {
				pressed.push(melody[i].second);
				count++;
				//���� ������ �Ѿ
				continue;
			}
			//���� �̹� ������ �ִ� ���̶�� ���� ������ �Ѿ
			if (pressed.top() == melody[i].second)
				continue;
			
			//ť�� ���� ���̶�� �߰�
			pressed.push(melody[i].second);
			count++;

		}
	}
	
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	int result;

	//�Է�
	cin >> n >> p;
	vector<pair<int, int>> melody(n, { 0,0 }); //��ε� ������ ����	
	for(int i=0; i<n; i++) {
		cin >> melody[i].first >> melody[i].second;
	}
	
	//����
	result = numOfMoving(melody);

	//���
	cout << result << '\n';
}