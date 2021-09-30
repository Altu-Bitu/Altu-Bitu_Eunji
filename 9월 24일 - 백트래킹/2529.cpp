#include <iostream>
#include <string>


using namespace std;

const int SIZE = 9;

int k;
char inputs[SIZE]; //부등호 입력받아서 저장할 배열
bool check[SIZE + 1]; //수열에 해당 수(인덱스) 들어있는지 체크할 배열
int num[SIZE + 1]; //부등호를 만족하는 수(수열) 저장할 배열
long long min_temp = 9999999999, max_temp; //최솟값, 최댓값을 구하기 위함
string ans_min, ans_max; //정답


//조건에 맞는지 체크하는 함수
bool promising(int cnt, int number) {
	if (cnt == 0) //cnt가 0이면 아직 부등호 등장 전이므로 재귀 호출
		return true;

	//부등호 조건 검사
	char input = inputs[cnt - 1];
	if ((input == '>' && num[cnt - 1] > number) || (input == '<' && num[cnt - 1] < number))
		return true;
	
	//조건에 부합하지 않으면 재귀 호출 안 함
	return false;
}

//조건에 부합하는 최솟값을 찾는 함수
void findMin(int cnt) {
	if (cnt == k + 1) { //기저조건 num의 길이가 부등호의 개수보다 1개 더 많은 경우
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num에 저장된 정수들 하나의 문자열(str)로 치환
		}

		if (min_temp > stoll(str)) {
			min_temp = stoll(str);
			ans_min = str;
		}
	}

	//최솟값(부등호가 k개이므로 0 ~ k+1의 수로 이루어짐)
	for (int i = 0; i <= k; i++) {
		if (!check[i]) {
			if (promising(cnt, i)) { //조건 만족하는지 체크
				num[cnt] = i;
				check[i] = true;
				findMin(cnt + 1);
				check[i] = false;
			}
		}
	}
}

void findMax(int cnt) { //cnt: num의 인덱스
	if (cnt == k + 1) { //기저조건 num의 길이가 부등호의 개수보다 1개 더 많은 경우
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num에 저장된 정수들 하나의 문자열(str)로 치환
		}
		
		if (max_temp < stoll(str)) {
			max_temp = stoll(str);
			ans_max = str;
		}
	}

	//최댓값( 9-k ~ 9로 이루어짐)
	for (int i = 9; i >= (9 - k); i--) {
		if (!check[i]) {
			if (promising(cnt, i)) { //조건 만족하는지 체크
				num[cnt] = i;
				check[i] = true;
				findMax(cnt + 1);
				check[i] = false;
			}
		}
	}
	
}

int main() {
	//입력
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> inputs[i];
	}

	//연산
	findMin(0);
	findMax(0);


	//출력
	cout << ans_max << '\n' << ans_min <<'\n';
}