#include<iostream>
#include<queue>
using namespace std;

long long makeMin(int m, priority_queue<long long, vector<long long>, greater<>> cards) {
	long long card, result = 0;
	while (m--) {
		card = cards.top();
		cards.pop();
		card += cards.top();
		cards.pop();
		
		cards.push(card);
		cards.push(card);
	}

	while (!cards.empty()) {
		result += cards.top();
		cards.pop();
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	long long input, result;
	//n���� ī�忡 ���� ���� ������ �ּ���
	priority_queue<long long, vector<long long>, greater<>> cards;

	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cards.push(input);
	}
	//����
	result = makeMin(m, cards);
	//���
	cout << result;
}