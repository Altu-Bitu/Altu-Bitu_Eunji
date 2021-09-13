#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> species;
	string input;
	int cnt = 0;
	//�Է�
	while (getline(cin, input)) {
		cnt++;
		species[input]++;
	}
	//�Ҽ��� ��°�ڸ�������
	cout << fixed;
	cout.precision(4);

	//���
	for (auto iter = species.begin(); iter != species.end(); iter++) {
		double p = (iter->second / (double)cnt) * 100;
		cout << iter->first << ' ' << p << '\n';
	}
}