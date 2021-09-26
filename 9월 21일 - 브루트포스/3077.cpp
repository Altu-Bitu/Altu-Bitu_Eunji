#include <iostream>
#include <vector>
#include <map>

using namespace std;

int grade(map<string, int> right, vector<string> student) {
	int result = 0;
	for (int i = 0; i < student.size() - 1; i++) {
		//i번째 바로 다음부터 상대적 순서를 맞게 적었는지 확인
		for (int j = i; j < student.size(); j++) {
			//i번째에 적은 해전보다 j번째 (i번째 이후라고 적은 해전들)에 적은 해전이 나중에 일어난 경우
			if (right[student[i]] < right[student[j]]) 
				result++; //점수 1점 추가
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int total;

	//입력
	cin >> n;
	map<string, int> right;
	vector<string> student(n, "");

	//정답 입력 받아서 순서와 함께 저장
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		right[input] = i;
	}

	for (int i = 0; i < n; i++)
		cin >> student[i];

	//연산
	total = grade(right, student);

	//출력
	cout << total << '/' << n * (n - 1) / 2 << '\n';
}