#include <iostream>
#include <deque>

using namespace std;


//비기면 0, 도도가 이기면 1, 수연이 이기면 2 반환
int whoIsWinner(int m, deque<int> &dodo, deque<int> &su) {
	int result;
	//그라운드는 카드 앞면 뱡향을 시작 지점(앞부분)으로 생각
	deque<int> ground_do; //도도의 그라운드
	deque<int> ground_su; //수연의 그라운드

	while (m && !dodo.empty() && !su.empty()) {
		
		//도도가 먼저 카드를 내려 놓는다.
		int card_dodo = dodo.front();
		dodo.pop_front();
		if (dodo.empty())
			break;
		ground_do.push_front(card_dodo);

		if (card_dodo == 5) { //만약 도도가 내놓은 카드가 5라면
			while (!ground_su.empty()) {
				dodo.push_back(ground_su.back());
				ground_su.pop_back();
			}

			while (!ground_do.empty()) {
				dodo.push_back(ground_do.back());
				ground_do.pop_back();
			}
		}
		if (!ground_su.empty() && ground_su.front() + card_dodo == 5) { //도도가 내놓은 카드와 수연의 그라운드에 있던 카드의 합이 5인 경우
			while (!ground_do.empty()) {
				su.push_back(ground_do.back());
				ground_do.pop_back();
			}
			while (!ground_su.empty()) {
				su.push_back(ground_su.back());
				ground_su.pop_back();
			}
		}
		m--;
		if (m == 0) break;
		
		//수연이 카드를 내려 놓는다.
		int card_su = su.front();
		su.pop_front();
		if (su.empty())
			break;
		ground_su.push_front(card_su);
		if (card_su == 5) { //만약 수연이 내놓은 카드가 5라면
			while (!ground_su.empty()) {
				dodo.push_back(ground_su.back());
				ground_su.pop_back();
			}

			while (!ground_do.empty()) {
				dodo.push_back(ground_do.back());
				ground_do.pop_back();
			}
		}
		if (!ground_do.empty() && ground_do.front() + card_su == 5) { //수연이 내놓은 카드와 도도의 그라운드에 있던 카드의 합이 5인 경우
			while (!ground_do.empty()) {
				su.push_back(ground_do.back());
				ground_do.pop_back();
			}
			while (!ground_su.empty()) {
				su.push_back(ground_su.back());
				ground_su.pop_back();
			}
		}

		m--;
	}

	//결과 반환
	if (su.size() == dodo.size())
		return 0;
	else if (su.size() < dodo.size())
		return 1;
	else
		return 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	//입력
	cin >> n >> m;

	//덱은 카드가 뒤집힌 방향을 시작 지점(앞부분)으로 생각
	deque<int> dodo; //도도의 덱
	deque<int> su; //수연의 덱

	for (int i = 0; i < n; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		dodo.push_front(temp1);
		su.push_front(temp2);
	}

	int result = whoIsWinner(m, dodo, su); 

	//출력
	if (result == 0)
		cout << "dosu" << '\n';
	else if (result == 1)
		cout << "do" << '\n';
	else
		cout << "su" << '\n';
}