#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numOfPass(int n, vector<pair<int, int>> score) {
	int result = 1;
	sort(score.begin(), score.end());

	int max_score = score[0].second;
	for (int j = 1; j < n; j++) {
		if (score[j].second < max_score) {
			max_score = score[j].second;
			result++;
		}
	}

	return result;
}

int main() {
	int test_case, n;
	vector<int>result;
	vector<pair<int, int>> score;

	//�Է�
	cin >> test_case;
	result.assign(test_case, 1);

	for (int i = 0; i < test_case; i++) {
		cin >> n;
		score.assign(n, {});
		for (int j = 0; j < n; j++) {
			cin >> score[j].first >> score[j].second;
		}
		
		result[i] = numOfPass(n, score);
	}

	//���
	for (int i = 0; i < test_case; i++) {
		cout << result[i] << "\n";
	}
}