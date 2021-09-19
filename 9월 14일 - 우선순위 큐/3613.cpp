#include<iostream>
#include<string>

using namespace std;

//� �������� �Ǵ��ϴ� �Լ�
//0�̸� ����, 1�̸� c++, 2�� java, 3�� �� ��ο� �ش�Ǵ� ���
int identify(string input) {
	bool cpp = true, java = true;
	int n = input.size();

	if ((input[0] >= 'A' && input[0] <= 'Z') || input[0] == '_' || input[n-1] == '_')
		return 0; //ù���� Ȥ�� �������� �����̰ų� ù���ڰ� �빮���̸� �����̹Ƿ� 0�� ��ȯ

	for (int i = 1; i < n; i++) {

		//�빮�� ����
		if (isupper(input[i])) {
			if (cpp && !java) { //�ռ� c++�̶�� �Ǵ��ߴ� ���
				cpp = false;
				break; //������ �Ǵ��ϰ� �ݺ��� Ż��
			}
			else { //�켱 java�� �Ǵ�
				java = true;
				cpp = false;
			}
		}

		//���� ����
		if (input[i] == '_') {
			if (java && !cpp) {//�ռ� java��� �Ǵ��ߴ� ���
				java = false;
				break; //������ �Ǵ��ϰ� �ݺ��� Ż��
			}
			else if (i < n-1 && input[i + 1] == '_') {//������ ���޾� ���� ���
				cpp = false;
				java = false;
				break; //������ �Ǵ��ϰ� �ݺ��� Ż��
			}
			else {
				cpp = true;
				java = false;
			}

		}
	}
	
	if (cpp && java) return 3;
	else if (java) return 2;
	else if (cpp) return 1;
	else return 0;
	
}

//���Ŀ� �°� ��ȯ�ϴ� �Լ�
string transform(int flag, string input) {
	int n = input.size();
	string result;

	if (flag == 0)
		return "Error!";
	else if (flag == 3) //�״�� ��ȯ
		return input;
	else if (flag == 1) { //c++������ java�������� ��ȯ
		for (int i = 0; i < n; i++) {
			if (input[i] == '_') {
				result += toupper(input[++i]);
			}
			else
				result += input[i];
		}
	}
	else { //java������ c++��������
		for (int i = 0; i < n; i++) {
			if (isupper(input[i])) {
				result += "_";
				input[i] = tolower(input[i]);
			}
			result += input[i];
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input, result;
	int flag;

	//�Է�
	cin >> input;

	//����
	flag = identify(input);
	result = transform(flag, input);

	//���
	cout << result;
}