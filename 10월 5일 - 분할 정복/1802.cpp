#include <iostream>

using namespace std;

//동호의 방법대로 다시 접을 수 있는지 확인하는 함수
bool canFold(int mid, string input) {
	//접힌 자국대로 모두 접은 경우
	if (mid <= 0)
		return true;

	//가운데 기준으로 왼쪽, 오른쪽 접은 방향이 같은지 다른지 확인하기 위한 인덱스
	int right = mid + 1;
	int left = mid - 1;

	while (left >= 0) {
		if (input[left] == input[right]) //종이 짝이 맞지 않아 접지 못하는 경우
			return false;
		left--;
		right++;
	}

	//가운데 기준으로 종이를 반으로 접을 수 있는 경우
	//그 종이를 다시 반으로 접을 수 있는지 확인해야 함
	return canFold(mid / 2, input); 
}

int main() {
	int t;

	//입력
	cin >> t;
	while (t--) {
		string input;
		cin >> input;

		//연산
		bool result = canFold(input.size() / 2, input);

		//출력
		if (result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}