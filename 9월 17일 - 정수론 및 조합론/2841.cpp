#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int numOfMoving(vector<pair<int, int>> melody) {
	int count = 0;
	int num = 7;

	stack<int> pressed[6];

	for (int i = 0; i < melody.size(); i++) {
		while (!pressed[melody[i].first - 1].empty() && pressed[melody[i].first - 1].top() > melody[i].second) {
			pressed[melody[i].first - 1].pop();
			count++;
		}
		if (pressed[melody[i].first-1].empty()) {
			pressed[melody[i].first-1].push(melody[i].second);
			count++;
			continue;
		}
		if (pressed[melody[i].first - 1].top() == melody[i].second)
			continue;

		pressed[melody[i].first - 1].push(melody[i].second);
		count++;
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