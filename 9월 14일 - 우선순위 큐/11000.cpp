#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int numOfClassroom(vector<pair<int, int>> time) {
	//각 강의실 당 끝나는 시간을 저장할 최소힙
	priority_queue<int, vector<int>, greater<>> pq;	

	pq.push(time[0].second);
	for (int i = 1; i < time.size(); i++) {
		if (pq.top() > time[i].first) { 
			//강의 끝나는 시간이 다음 수업의 시작 시간보다 늦다면 새로운 강의실 필요
			//새로운 강의실에는 강의가 끝나는 시간을 저장
			pq.push(time[i].second);
		}
		else {
			//강의실이 추가적으로 필요하지 않다면 끝나는 시간 갱신
			pq.pop();
			pq.push(time[i].second);
		}
	}

	return pq.size(); //강의실 개수(우선순위 큐의 크기) 반환
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, result;
	vector<pair<int, int>> time;

	//입력
	cin >> n;
	time.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}
	//시작 시간 기준으로 time 정렬
	sort(time.begin(), time.end());

	//연산
	result = numOfClassroom(time);

	//출력
	cout << result;
}