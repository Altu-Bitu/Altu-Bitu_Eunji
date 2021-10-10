#include <iostream>

using namespace std;

//�ִ� ã�� �Լ�
string findMax(string input) {
	string result = "";
	int size = input.size();

	//�� �ڸ����� �˻�
	for (int i = 0; i < size; i++) {
		if (input[i] == 'M') { //M�� ���� ���
			int temp = i + 1;
			//K�� ���� ������ �ε���(temp) ����
			while (temp < size && input[temp] != 'K')
				temp++;

			//K�� ������ �ʾҴٸ�
			if (temp == size)
				result += '1'; //result�� 1 �߰�
			else { //k�� ���Դٸ� result�� 5�� ó�� M �������� ���� M~K�� ������ŭ 0 �߰�
				result += '5';
				for (int j = 0; j < temp - i; j++)
					result += '0';
				i = temp; //i �� ����(stirng[temp] ���ĺ��� �˻��ϵ���)
			}
		}
		else { //K�� ���� ���
			result += '5'; //result�� 5 �߰�
		}
	}

	return result;
}

//�ּڰ� ã�� �Լ�
string findMin(string input) {
	string result = "";
	int size = input.size();

	for (int i = 0; i < size; i++) {
		if (input[i] == 'M') { //M�� ���
			int temp = i + 1;
			//K�� ������ ������ �ε��� ����
			while (temp < size && input[temp] == 'M')
				temp++;

			//�ٷ� ���� �ε����� K�� �ִٸ� result�� 1 �߰�
			if (temp == i + 1)
				result += '1';
			else { //M�� �������� ���� ���
				temp--; //K ���������� 0�� �߰��ؾ� �ϹǷ� �ε��� �ϳ� ����
				result += '1'; //result�� 1 �߰� �� ó�� M �������� ���� M�� ������ŭ 0 �߰�
				for (int j = 0; j < temp - i; j++)
					result += '0';
				i = temp; //i �� ����
			}
		}
		else { //K�� ���
			result += '5';
		}
	}

	return result;
}

int main() {
	string input;

	//�Է�
	cin >> input;

	//���� + ���
	cout << findMax(input) << '\n' << findMin(input) << '\n';
}