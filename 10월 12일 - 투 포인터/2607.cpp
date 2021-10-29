#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int similarCount(int n, vector<string> words) {
	int ans = 0;
	string first = words[0]; //ù��° �ܾ�
	int length_first = words[0].size(); //ù��° �ܾ��� ���� 
	
	map<char, int> construction_first; //ù��° �ܾ ����ִ� ������ ���� ����
	vector<bool> check(26, false); //ù��° �ܾ ����ִ� �������� üũ�ϱ� ���� �迭
	for (int i = 0; i < length_first; i++) {
		construction_first[first[i]]++;
		check[first[i] - 'A'] = true;
	}

	for (int i = 1; i < n; i++) {
		string temp = words[i]; //���� �ܾ�
		int length_temp = words[i].size(); //ù��° �ܾ�� ���� �ܾ��� ����

		if (abs(length_temp - length_first) > 1) //�ܾ� ������ ���̰� 1���� ũ�� ����� �ܾ �ƴ�
			continue;

		map<char, int> construction_temp = construction_first; //ù��° �ܾ��� ���� ����
		int different = 0; //�� �ܾ��� ����

		//����� �ܾ����� �˻�
		if (length_temp < length_first) { //�ܾ��� ���̰� �� ª�� ��� -> ���� �߰��� ����
			for (int j = 0; j < length_temp; j++) {
				//ù��° �ܾ ���� �����̰ų� �����ϴ� �����̳� ������ �� ���� ��� -> ��ü, ���� �ʿ�
				if (!check[temp[j] - 'A'] || (check[temp[j] - 'A'] && construction_temp[temp[j]] == 0)) { 
					different = 2;
					break;
				}
				//�ش� ���� �����ϸ� ���� ������ 0���� ŭ -> �ϳ� ����
				construction_temp[temp[j]]--;
			}
		}
		else { //�ܾ��� ���̰� ��ų� ���� ���
			for (int j = 0; j < length_temp; j++) {
				//ù��° �ܾ �ش� ���ڰ� ������ ��� -> ���� �ϳ��� ���� ��Ű�� üũ
				if (check[temp[j] - 'A']) {
					if (construction_temp[temp[j]] > 0) //���� ������ 0���� ŭ
						construction_temp[temp[j]]--; //���� �ϳ� ����
					else if (construction_temp[temp[j]] == 0) { //ù��° �ܾ �����ϴ� �����̳� ������ �� ����
						different++; //���� ����
					}
				}
				else //ù��° �ܾ �������� �ʴ� ������ ���(��ü or ����)
					different++;

				//���̰� 2�� �̻��̸� ���� �������� �ٲ� �� ����(����� �ܾ �ƴ�)
				if (different >= 2)
					break;
			}
		}
		
		if (different <= 1) { //����� �ܾ��̸�
			ans++;
			different = 0;
		}
	}
	return ans;
}

int main() {
	int n;
	string word;

	//�Է�
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];

	//���� �� ���
	cout << similarCount(n, words) << '\n';
}