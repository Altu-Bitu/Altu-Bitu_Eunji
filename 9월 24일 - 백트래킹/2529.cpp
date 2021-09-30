#include <iostream>
#include <string>


using namespace std;

const int SIZE = 9;

int k;
char inputs[SIZE]; //�ε�ȣ �Է¹޾Ƽ� ������ �迭
bool check[SIZE + 1]; //������ �ش� ��(�ε���) ����ִ��� üũ�� �迭
int num[SIZE + 1]; //�ε�ȣ�� �����ϴ� ��(����) ������ �迭
long long min_temp = 9999999999, max_temp; //�ּڰ�, �ִ��� ���ϱ� ����
string ans_min, ans_max; //����


//���ǿ� �´��� üũ�ϴ� �Լ�
bool promising(int cnt, int number) {
	if (cnt == 0) //cnt�� 0�̸� ���� �ε�ȣ ���� ���̹Ƿ� ��� ȣ��
		return true;

	//�ε�ȣ ���� �˻�
	char input = inputs[cnt - 1];
	if ((input == '>' && num[cnt - 1] > number) || (input == '<' && num[cnt - 1] < number))
		return true;
	
	//���ǿ� �������� ������ ��� ȣ�� �� ��
	return false;
}

//���ǿ� �����ϴ� �ּڰ��� ã�� �Լ�
void findMin(int cnt) {
	if (cnt == k + 1) { //�������� num�� ���̰� �ε�ȣ�� �������� 1�� �� ���� ���
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num�� ����� ������ �ϳ��� ���ڿ�(str)�� ġȯ
		}

		if (min_temp > stoll(str)) {
			min_temp = stoll(str);
			ans_min = str;
		}
	}

	//�ּڰ�(�ε�ȣ�� k���̹Ƿ� 0 ~ k+1�� ���� �̷����)
	for (int i = 0; i <= k; i++) {
		if (!check[i]) {
			if (promising(cnt, i)) { //���� �����ϴ��� üũ
				num[cnt] = i;
				check[i] = true;
				findMin(cnt + 1);
				check[i] = false;
			}
		}
	}
}

void findMax(int cnt) { //cnt: num�� �ε���
	if (cnt == k + 1) { //�������� num�� ���̰� �ε�ȣ�� �������� 1�� �� ���� ���
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num�� ����� ������ �ϳ��� ���ڿ�(str)�� ġȯ
		}
		
		if (max_temp < stoll(str)) {
			max_temp = stoll(str);
			ans_max = str;
		}
	}

	//�ִ�( 9-k ~ 9�� �̷����)
	for (int i = 9; i >= (9 - k); i--) {
		if (!check[i]) {
			if (promising(cnt, i)) { //���� �����ϴ��� üũ
				num[cnt] = i;
				check[i] = true;
				findMax(cnt + 1);
				check[i] = false;
			}
		}
	}
	
}

int main() {
	//�Է�
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> inputs[i];
	}

	//����
	findMin(0);
	findMax(0);


	//���
	cout << ans_max << '\n' << ans_min <<'\n';
}