#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 9;

int k;
char inputs[SIZE]; //부등호 입력받아서 저장할 배열
bool check[SIZE + 1]; //수열에 해당 수(인덱스) 들어있는지 체크할 배열
int num[SIZE + 1]; //부등호를 만족하는 수(수열) 저장할 배열
vector<string> result; //부등호 만족하는 모든 수 저장할 배열


void findNum(int cnt) { //cnt: num의 인덱스
	if (cnt == k + 1) { //기저조건 num의 길이가 부등호의 개수보다 1개 더 많은 경우
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num에 저장된 정수들 하나의 문자열(str)로 치환
		}
		result.push_back(str); //result에 str 담는다.
	}

	//0~9까지 들어갈 수 있으므로 0~9까지 반복문 돌림
	for (int i = 0; i <= SIZE; i++) {
		if (cnt == 0) { //아직 부등호가 나오기 전이므로 일단 num에 담고 재귀 호출
			num[cnt] = i;
			check[i] = true; //check 배열에 표시
			findNum(cnt + 1);
			check[i] = false; //원래 상태로 돌려 놓는다.
			continue; //다음 수(i+1) 넣어서 처음부터 수열을 만들어야 하므로 continue
		}

		if (!check[i]) {
			char temp = inputs[cnt - 1]; //입력으로 받은 부등호
			if ((temp == '>' && num[cnt - 1] > i) || (temp == '<' && num[cnt - 1] < i)) { //부등호 조건 만족하는지 체크
				num[cnt] = i;
				check[i] = true;
				findNum(cnt + 1);
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
	findNum(0);

	//결과로 받은 벡터 정렬
	sort(result.begin(), result.end());

	//최솟값과 최댓값만 출력
	cout << result[result.size() - 1] << '\n' << result[0] <<'\n';
}