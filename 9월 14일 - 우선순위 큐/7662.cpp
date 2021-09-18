#include <iostream>
#include <map>
using namespace std;


void insertInt(int x, map<int, int>&q) {
	q[x] += 1;
}

void deleteInt(int x, map<int, int>&q) {
	if (x == 1) {
		auto iter = --q.end();
		if (iter->second < 2)
			q.erase(iter);
		else
			iter->second--;
	}
	else {
		auto iter = q.begin();
		if (iter->second < 2)
			q.erase(iter);
		else
			iter->second--;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, x; //입력 데이터 수, 연산의 개수, 연산과 함께 입력될 정수
	string cmd;

	cin >> t;
	while (t--) {
		map<int, int> dual_priority_queue;
		cin >> n;
		while (n--) {
			cin >> cmd;
			if (cmd == "I") {
				cin >> x;
				insertInt(x, dual_priority_queue);
				continue;
			}
			if (cmd == "D") {
				cin >> x;
				if (dual_priority_queue.empty())
					continue;
				deleteInt(x, dual_priority_queue);
				continue;
			}
		}
		if (dual_priority_queue.empty())
			cout << "EMPTY" << '\n';
		else {
			auto iter1 = dual_priority_queue.begin();
			auto iter2 = --dual_priority_queue.end();
			cout << iter2->first << ' ' << iter1->first << '\n';
		}
	
	}
}