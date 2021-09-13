#include<iostream>

using namespace std;

struct diet_info {
	//���뷮, Ȱ����緮, �Ⱓ, ���ʴ�緮 ��ġ
	int intake, a_metabolism, day, t;
};

struct diet_result {
	int yoyo1, yoyo2, w1, w2, i_metabolism_after;
	//���ʴ�緮 ������� ���� ��� ��� ����, ������� ���� ��� ����
	//������� ���� ��� ü��, ������� ���� ü��
	//���̾�Ʈ �� ���ʴ�緮(���ʴ�緮 ����� ���)
};

// 0�� ��ȯ�ϸ� ���, 1�� ��ȯ�ϸ� ���, 2�� ��ȯ�ϸ� ���x
int isYoyo(int w, int intake, int i_metabolism) {
	if (w <= 0 || i_metabolism <= 0) return 0;

	if (intake > i_metabolism) return 1;
	else return 2;
}

//���� ��緮 ���
struct diet_result diet(struct diet_info info, int w, int i_metabolism) {
	int i_metabolism_after = i_metabolism;
	int w1 = w, w2 = w; //���� ���� ������ ���� ���� ü��, ���� ���� ü�� (���̾�Ʈ ��)
	int yoyo1, yoyo2; //���, ��� ���� ������ ����
	struct diet_result result; //��ȯ�� �� �����ϴ� ����

	int total1 = info.intake - (info.a_metabolism + i_metabolism); //���� ����-���� �Һ�(���� ��緮 ����)
	int total2 = info.intake - (info.a_metabolism + i_metabolism_after); //���� ����-���� �Һ�(���� ��緮 ��ȭ)
	
	
	
	while (info.day--) {
		w1 += total1;
		w2 += total2;

		if (abs(total2) > info.t) {
			if (total2 < 0 && total2 % 2 != 0)
				i_metabolism_after += (total2 / 2 - 1);
			else
				i_metabolism_after += (total2 / 2);
			
			total2 = info.intake - (info.a_metabolism + i_metabolism_after);
		}
	}

	//��� ����
	yoyo1 = isYoyo(w1, i_metabolism, i_metabolism);
	yoyo2 = isYoyo(w2, i_metabolism, i_metabolism_after);

	result.yoyo1 = yoyo1;
	result.yoyo2 = yoyo2;
	result.w1 = w1;
	result.w2 = w2;
	result.i_metabolism_after = i_metabolism_after;

	return result;	
}



int main() {
	int w; //ü��(���̾�Ʈ ��,��)
	int i_metabolism; //���ʴ�緮(���̾�Ʈ ��,��)
	struct diet_info info; //���̾�Ʈ ���� ����
	struct diet_result result; //���̾�Ʈ ���

	//�Է�
	cin >> w >> i_metabolism >> info.t
		>> info.day >> info.intake >> info.a_metabolism;

	//���
	result = diet(info, w, i_metabolism);

	//���� ��緮 ��ȭ ���� ���� ��� ���
	if (result.yoyo1 != 0)
		cout << result.w1 << ' ' << i_metabolism << '\n';
	else
		cout << "Danger Diet\n";

	//���� ��緮 ��ȭ ���� ���� ��� ���
	if (result.yoyo2 == 0)
		cout << "Danger Diet\n";
	if (result.yoyo2 == 1)
		cout << result.w2 << ' ' << result.i_metabolism_after << " YOYO";
	if (result.yoyo2 == 2)
		cout << result.w2 << ' ' << result.i_metabolism_after << " NO";

}