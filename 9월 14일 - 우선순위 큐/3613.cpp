#include<iostream>
#include<string>

using namespace std;

//어떤 형식인지 판단하는 함수
//0이면 에러, 1이면 c++, 2면 java, 3은 둘 모두에 해당되는 경우
int identify(string input) {
	bool cpp = true, java = true;
	int n = input.size();

	if ((input[0] >= 'A' && input[0] <= 'Z') || input[0] == '_' || input[n-1] == '_')
		return 0; //첫글자 혹은 마지막이 밑줄이거나 첫글자가 대문자이면 에러이므로 0을 반환

	for (int i = 1; i < n; i++) {

		//대문자 등장
		if (isupper(input[i])) {
			if (cpp && !java) { //앞서 c++이라고 판단했던 경우
				cpp = false;
				break; //에러로 판단하고 반복문 탈출
			}
			else { //우선 java로 판단
				java = true;
				cpp = false;
			}
		}

		//밑줄 등장
		if (input[i] == '_') {
			if (java && !cpp) {//앞서 java라고 판단했던 경우
				java = false;
				break; //에러로 판단하고 반복문 탈출
			}
			else if (i < n-1 && input[i + 1] == '_') {//밑줄이 연달아 나온 경우
				cpp = false;
				java = false;
				break; //에러로 판단하고 반복문 탈출
			}
			else {
				cpp = true;
				java = false;
			}

		}
	}
	
	if (cpp && java) return 3;
	else if (java) return 2;
	else if (cpp) return 1;
	else return 0;
	
}

//형식에 맞게 변환하는 함수
string transform(int flag, string input) {
	int n = input.size();
	string result;

	if (flag == 0)
		return "Error!";
	else if (flag == 3) //그대로 반환
		return input;
	else if (flag == 1) { //c++형식을 java형식으로 변환
		for (int i = 0; i < n; i++) {
			if (input[i] == '_') {
				result += toupper(input[++i]);
			}
			else
				result += input[i];
		}
	}
	else { //java형식을 c++형식으로
		for (int i = 0; i < n; i++) {
			if (isupper(input[i])) {
				result += "_";
				input[i] = tolower(input[i]);
			}
			result += input[i];
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input, result;
	int flag;

	//입력
	cin >> input;

	//연산
	flag = identify(input);
	result = transform(flag, input);

	//출력
	cout << result;
}