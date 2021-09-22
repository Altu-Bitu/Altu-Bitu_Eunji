#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfMoving(vector<pair<int, int>> melody) {
	int count = 0;
	int num = 7;

	//줄의 수가 많지 않고 줄이 다르면 손가락 움직임에 영향을 주지 않으므로 줄마다 손가락 움직임 count
	while (--num) {
		//어떤 프렛을 누르고 있는지 저장할 우선순위 큐(최대힙)
		priority_queue<int> pressed;
		for (int i = 0; i < melody.size(); i++) {
			//해당 줄이 아니면 pass
			if (melody[i].first != num)
				continue;
			
			//우선순위 큐가 비어있지 않고 저장된 가장 높은 음이 누르고자 하는 프렛보다 높은 음이면
			while (!pressed.empty() && pressed.top() > melody[i].second) {
				//가장 높은 음 제거 후 count 증가
				pressed.pop();
				count++;
			}
			//우선순위 큐가 비어있다면 누르고자 하는 프렛 저장
			if (pressed.empty()) {
				pressed.push(melody[i].second);
				count++;
				//다음 음으로 넘어감
				continue;
			}
			//만약 이미 누르고 있는 음이라면 다음 음으로 넘어감
			if (pressed.top() == melody[i].second)
				continue;
			
			//큐에 없는 음이라면 추가
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

	//입력
	cin >> n >> p;
	vector<pair<int, int>> melody(n, { 0,0 }); //멜로디 저장할 벡터	
	for(int i=0; i<n; i++) {
		cin >> melody[i].first >> melody[i].second;
	}
	
	//연산
	result = numOfMoving(melody);

	//출력
	cout << result << '\n';
}