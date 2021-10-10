#include <iostream>

using namespace std;

//최댓값 찾는 함수
string findMax(string input) {
	string result = "";
	int size = input.size();

	//앞 자리부터 검사
	for (int i = 0; i < size; i++) {
		if (input[i] == 'M') { //M이 나온 경우
			int temp = i + 1;
			//K가 나올 때까지 인덱스(temp) 증가
			while (temp < size && input[temp] != 'K')
				temp++;

			//K가 나오지 않았다면
			if (temp == size)
				result += '1'; //result에 1 추가
			else { //k가 나왔다면 result에 5와 처음 M 다음부터 나온 M~K의 개수만큼 0 추가
				result += '5';
				for (int j = 0; j < temp - i; j++)
					result += '0';
				i = temp; //i 값 갱신(stirng[temp] 이후부터 검사하도록)
			}
		}
		else { //K가 나온 경우
			result += '5'; //result에 5 추가
		}
	}

	return result;
}

//최솟값 찾는 함수
string findMin(string input) {
	string result = "";
	int size = input.size();

	for (int i = 0; i < size; i++) {
		if (input[i] == 'M') { //M인 경우
			int temp = i + 1;
			//K가 나오기 전까지 인덱스 증가
			while (temp < size && input[temp] == 'M')
				temp++;

			//바로 다음 인덱스에 K가 있다면 result에 1 추가
			if (temp == i + 1)
				result += '1';
			else { //M이 연속으로 나온 경우
				temp--; //K 직전까지만 0을 추가해야 하므로 인덱스 하나 감소
				result += '1'; //result에 1 추가 후 처음 M 다음부터 나온 M의 개수만큼 0 추가
				for (int j = 0; j < temp - i; j++)
					result += '0';
				i = temp; //i 값 갱신
			}
		}
		else { //K인 경우
			result += '5';
		}
	}

	return result;
}

int main() {
	string input;

	//입력
	cin >> input;

	//연산 + 출력
	cout << findMax(input) << '\n' << findMin(input) << '\n';
}