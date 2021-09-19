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
	//n장의 카드에 적힌 수를 저장할 최소힙
	priority_queue<long long, vector<long long>, greater<>> cards;

	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cards.push(input);
	}
	//연산
	result = makeMin(m, cards);
	//출력
	cout << result;
}