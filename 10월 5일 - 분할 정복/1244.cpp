#include <iostream>
#include <vector>

using namespace std;

//스위치 상태 바꾸는 함수
int change(int current_switch) {
	if (current_switch) return 0;
	else return 1;
}

//스위치의 마지막 상태 출력
vector<int> finalSwitch(vector<int> switch_state, vector<pair<int, int>> student) {
	int switch_n = switch_state.size();
	int student_n = student.size();

	for (int i = 0; i < student_n; i++) {
		if (student[i].first == 1) { //남학생인 경우
			int num = student[i].second; //남학생이 받은 번호
			while (num < switch_n) { //스위치 번호보다 작거나 같은 경우 반복
				switch_state[num] = change(switch_state[num]);
				num += student[i].second;
			}
		}
		else { //여학생인 경우
			int num = student[i].second; //여학생이 받은 번호
			switch_state[num] = change(switch_state[num]); //우선 받은 번호에 해당하는 스위치 상태 변경
			int left = num - 1, right = num + 1;

			while (left >= 1 && right < switch_n) {
				if (switch_state[left] != switch_state[right]) //좌우 대칭이 아니면
					break; //반복문 탈출
				else { //좌우 대칭이면
					switch_state[left] = change(switch_state[left]); //스위치 상태 변경
					switch_state[right] = switch_state[left];
					left--; //왼쪽 인덱스와 오른쪽 인덱스 변경
					right++;
				}
			}
		}
	}

	return switch_state;
}

int main() {
	int switch_n, student_n; //스위치 개수, 학생 수

	//입력
	cin >> switch_n;
	vector<int> switch_state (switch_n + 1, 0);
	for (int i = 1; i <= switch_n; i++)
		cin >> switch_state[i];

	cin >> student_n;
	vector<pair<int, int>> student(student_n);
	for (int i = 0; i < student_n; i++) {
		cin >> student[i].first >> student[i].second;
	}

	//연산
	vector<int>switch_result = finalSwitch(switch_state, student);

	//출력
	int cnt = 0;
	for (int i = 1; i <= switch_n; i++) {
		if (cnt == 20) {
			cout << '\n';
			cnt = 0;
		}
		cout << switch_result[i] <<' ';
		cnt++;
	}
}