#include<iostream>
#include<queue>
using namespace std;

//과목당 듣기 위해 필요한 최소한의 마일리지
int mileageNeeded(int P, int L){
	//각 사람이 넣은 마일리지를 입력받아 저장할 변수
	int input_m;
	//크기를 수강인원(L)로 유지하며 각사람이 넣은 마일리지를 저장할 최소힙
	priority_queue<int, vector<int>, greater<>> pq;

	//수강인원보다 신청인원이 적은 경우
	if (P < L) {
		while (P--)
			cin >> input_m;
		return 1;
	}

	for (int i = 0; i < P; i++) {
		cin >> input_m;
		if (pq.size() < L)
			pq.push(input_m);
		else {
			if (pq.top() < input_m) {
				pq.pop();
				pq.push(input_m);
			}
		}
	}

	return pq.top();
	
}

//들을 수 있는 과목 개수
int numOfCourses(int m, priority_queue<int, vector<int>, greater<>> pq) {
	int result = 0;
	while (!pq.empty()) {
		if (m >= pq.top()) {
			m -= pq.top();
			pq.pop();
			result++;
		}
		else
			break;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int P, L; //신청한 사람 수, 수강인원
	int result;
	//각 수업을 듣는데 필요한 최소한의 마일리지를 저장할 최소힙
	priority_queue<int, vector<int>, greater<>> mileage;

	//입력 및 연산
	cin >> n >> m;

	while (n--) {
		cin >> P >> L;
		mileage.push(mileageNeeded(P, L));
	}

	result = numOfCourses(m, mileage);

	//출력
	cout << result << '\n';
}