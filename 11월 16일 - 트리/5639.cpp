#include <iostream>
#include <vector>

using namespace std;
vector<int> post_order; //���� ��ȸ ���
vector<int> pre_order; //���� ��ȸ ���

//���� ��ȸ ���: ��Ʈ>��>�� ����. ��Ʈ���� ū ��尡 ������ ������ ������ ����Ʈ���� ������.
//���� ��ȸ ������� Ʈ���� ����, ������ ����Ʈ���� ������ ���� ���� ��ȸ ����
void postOrder(int left, int right) { //left �Է¹��� Ʈ���� ������, right: Ʈ���� �� + 1 ����
	if (left == right) //���Ұ� ���� Ʈ���̹Ƿ� ����
		return;

	if (left + 1 == right) { //���� 1��
		post_order.push_back(pre_order[left]); //���� ��ȸ ����� ����
		return;
	}

	//����, ������ ����Ʈ�� ������ ��� ã��
	int temp = left + 1;
	while (temp < right && pre_order[temp] < pre_order[left])
		temp++;

	postOrder(left + 1, temp); //���� ����Ʈ������ ���� ��ȸ
	postOrder(temp, right); //������ ����Ʈ������ ���� ��ȸ
	post_order.push_back(pre_order[left]); //���� ��ȸ ����� ��Ʈ ����
}

int main() {
	//�Է�
	int input;
	while (cin >> input) 
		pre_order.push_back(input);

	//����
	postOrder(0, pre_order.size());

	//���
	for (int i = 0; i < post_order.size(); i++)
		cout << post_order[i] << '\n';
}