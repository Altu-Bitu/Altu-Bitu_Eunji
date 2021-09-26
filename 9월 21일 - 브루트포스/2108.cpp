#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//평균 구하는 함수
double mean(vector<int> numbers) {
	double sum = 0;
	for (int i = 0; i < numbers.size(); i++)
		sum += (double)numbers[i];

	return sum / numbers.size();
}

//중앙값 구하는 함수
int mid(vector<int> numbers) {
	return numbers[numbers.size() / 2];
}

//최빈값 구하는 함수
int mode(vector<int> numbers) {
	//numbers에 있는 수들이 몇번 등장하는지 저장할 벡터
	vector<pair<int,int>> count;

	//횟수(cnt)는 1로 초기화, 이전 인덱스 값(temp)는 number[0]으로 초기화
	int cnt = 1, temp = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		//만약 직전 인덱스에 저장된 값과 현재 인덱스에 저장된 값이 갔다면
		if (numbers[i] == temp) {
			cnt++; //횟수 증가
		}
		else { //직전 인덱스에 저장된 값과 다르다면
			count.push_back({ cnt, temp }); //횟수와 그 값을 count 벡터에 저장
			cnt = 1; //cnt, temp값 초기화
			temp = numbers[i];
		}
	}
	//numbers의 크기가 1이거나 
	//마지막 원소가 바로 직전 원소와 값과 다르다면
	//위에서 count에 저장되지 않으므로 따로 저장
	if (numbers.size() == 1 || temp != count[count.size() - 1].second) {
		count.push_back({ cnt, temp });
	}

	//가장 큰 cnt를 찾기 위해 count 정렬
	sort(count.begin(), count.end());
	
	
	int cnt2 = 0; //만약 최빈값이 여러 개 있는 경우 그 개수를 저장하기 위한 변수
	for (int i = count.size() - 1; i >= 0; i--) {
		//count의 제일 마지막 원소(cnt)와 count[i]에 저장된 원소(cnt)가 같다면 count[i]에 저장된 값 또한 최빈값임
		//따라서 그 두 값이 같다면 cnt2 증가 아니면 반복문 탈출
		if (count[i].first != count[count.size() - 1].first)
			break;
		cnt2++;
	}

	//최빈값이 여러 개인 경우-> 두번째로 작은 값 출력
	if (cnt2 > 1)
		return count[count.size() - cnt2 + 1].second;
	//최빈값이 하나인 경우 -> count의 제일 마지막 원소 출력
	return count[count.size() - cnt2].second;
	
}

//범위 구하는 함수
int range(vector<int> numbers) {
	return numbers[numbers.size() - 1] - numbers[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	//입력
	cin >> n;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end()); //통계값들을 구하기 위해 우선 입력받은 숫자들 정렬

	//연산 및 출력
	cout << round(mean(numbers)) << '\n' << mid(numbers) << '\n' << mode(numbers) << '\n' << range(numbers) << '\n';
}