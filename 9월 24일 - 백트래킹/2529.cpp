#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 9;

int k;
char inputs[SIZE]; //�ε�ȣ �Է¹޾Ƽ� ������ �迭
bool check[SIZE + 1]; //������ �ش� ��(�ε���) ����ִ��� üũ�� �迭
int num[SIZE + 1]; //�ε�ȣ�� �����ϴ� ��(����) ������ �迭
vector<string> result; //�ε�ȣ �����ϴ� ��� �� ������ �迭


void findNum(int cnt) { //cnt: num�� �ε���
	if (cnt == k + 1) { //�������� num�� ���̰� �ε�ȣ�� �������� 1�� �� ���� ���
		string str = "";
		for (int i = 0; i < k + 1; i++) {
			str += to_string(num[i]); //num�� ����� ������ �ϳ��� ���ڿ�(str)�� ġȯ
		}
		result.push_back(str); //result�� str ��´�.
	}

	//0~9���� �� �� �����Ƿ� 0~9���� �ݺ��� ����
	for (int i = 0; i <= SIZE; i++) {
		if (cnt == 0) { //���� �ε�ȣ�� ������ ���̹Ƿ� �ϴ� num�� ��� ��� ȣ��
			num[cnt] = i;
			check[i] = true; //check �迭�� ǥ��
			findNum(cnt + 1);
			check[i] = false; //���� ���·� ���� ���´�.
			continue; //���� ��(i+1) �־ ó������ ������ ������ �ϹǷ� continue
		}

		if (!check[i]) {
			char temp = inputs[cnt - 1]; //�Է����� ���� �ε�ȣ
			if ((temp == '>' && num[cnt - 1] > i) || (temp == '<' && num[cnt - 1] < i)) { //�ε�ȣ ���� �����ϴ��� üũ
				num[cnt] = i;
				check[i] = true;
				findNum(cnt + 1);
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
	findNum(0);

	//����� ���� ���� ����
	sort(result.begin(), result.end());

	//�ּڰ��� �ִ񰪸� ���
	cout << result[result.size() - 1] << '\n' << result[0] <<'\n';
}