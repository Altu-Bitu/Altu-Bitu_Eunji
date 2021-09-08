#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int test_case, n;
	vector<int>result;
	vector<pair<int, int>> score;

	cin >> test_case;
	result.assign(test_case, 1);

	for (int i = 0; i < test_case; i++) {
		cin >> n;
		score.assign(n, {});
		for (int j = 0; j < n; j++) {
			cin >> score[j].first >> score[j].second;
		}
		sort(score.begin(), score.end());

		int max_score = score[0].second;
		for (int j = 1; j < n; j++) {
			if (score[j].second < max_score) {
				max_score = score[j].second;
				result[i]++;
			}
		}
	}

	for (int i = 0; i < test_case; i++) {
		cout << result[i] << "\n";
	}
}