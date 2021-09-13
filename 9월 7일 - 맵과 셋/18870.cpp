#include<iostream>
#include<vector>
#include<map>

using namespace std;

void countSmaller(vector<int> x) {
	map<int, int> temp;

	for (int i = 0; i < x.size(); i++) { //�Է¹��� ��ǥ���� map�� key�� ����
		temp[x[i]] = 0;
	}

	int cnt = 0;
	for (auto iter = temp.begin(); iter != temp.end(); iter++) {
		iter->second = cnt++; //�� key���� ���� key�� ������ value�� ����
	}

	for (int i = 0; i < x.size(); i++)
		cout << temp[x[i]] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> x;
	map<int, int> result;

	//�Է�
	cin >> n;
	x.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	//���
	countSmaller(x);
}