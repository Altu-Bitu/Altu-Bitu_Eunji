#include<iostream>
#include<queue>
using namespace std;

//과목당 듣기 위해 필요한 최소한의 마일리지
int mileageNeeded(int P, int L, vector<int> mileage_p){
	//크기를 수강인원(L)로 유지하며 각사람이 넣은 마일리지를 저장할 최소힙
	priority_queue<int, vector<int>, greater<>> pq;

	if (P < L) return 1;

	for (int i = 0; i < P; i++) {
		if (pq.size() < L)
			pq.push(mileage_p[i]);
		else {
			if (pq.top() < mileage_p[i]) {
				pq.pop();
				pq.push(mileage_p[i]);
			}
		}
	}

	return pq.top();
	
}

//들을 수 있는 과목 개수
int numOfCourses(int m, priority_queue<int, vector<int>, greater<>> pq) {
	int result = 0;
	while (!pq.empty() && m >= pq.top()) {
			m -= pq.top();
			pq.pop();
			result++;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, input_m;
	int P, L; //신청한 사람 수, 수강인원
	vector<int> mileage_p; //신청한 사람들이 넣은 마일리지 저장할 배열
	int result;
	//각 수업을 듣는데 필요한 최소한의 마일리지를 저장할 최소힙
	priority_queue<int, vector<int>, greater<>> mileage;

	//입력 및 연산
	cin >> n >> m;

	while (n--) {
		cin >> P >> L;
		mileage_p.assign(P, 0);
		for(int i=0; i<P; i++) {
			cin >> mileage_p[i];
		}
		mileage.push(mileageNeeded(P, L, mileage_p));
	}

	result = numOfCourses(m, mileage);

	//출력
	cout << result << '\n';
}