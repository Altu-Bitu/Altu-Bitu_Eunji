#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

//비교함수 (최빈값 구하는 함수에서 사용)
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

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
	//numbers에 있는 수들이 몇번 등장하는지 저장할 맵
	map<int, int> count;
	
	for (int i = 0; i < numbers.size(); i++) {
		count[numbers[i]]++;
	}
	
	//빈도(value)순으로 정렬하기 위해 벡터 선언
	vector<pair<int, int>> freq(count.begin(), count.end());
	sort(freq.begin(), freq.end(),cmp); //빈도를 내림차순으로 정렬

	int cnt = 1;
	for (int i = 1; i < freq.size(); i++) {
		//freq[i]의 값이 freq의 제일 첫 원소(최대 빈도수)와 같다면 freq[i]에 저장된 값 또한 최빈값
		if (freq[i].second != freq[0].second)
			break;
		cnt++;
	}
	
	//최빈값이 여러 개인 경우 두번째로 작은 값 출력
	//freq 정렬 시 정렬함수에서 pair의 두번째 인자가 같은 경우 첫번째 인자를 오름차순으로 정렬하도록 했으므로 1번 인덱스 원소가 두번째로 작은 값임.
	if (cnt > 1)
		return freq[1].first;
	else
		return freq[0].first;
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