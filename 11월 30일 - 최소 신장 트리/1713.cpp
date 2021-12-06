#include<iostream>
#include<vector>
#include <map>
#include<algorithm>

using namespace std;

//����Ʋ�� �� á���� Ȯ���ϴ� �Լ�
bool isFull(int n, int student, int order, vector<pair<int, int>> &photo) {
	for (int i = 0; i < n; i++) {
		if (photo[i].first == student) //������ �̹� �Խõ� ���
			return false;
		else if (photo[i].first == 0) { //����ִ� ����Ʋ�� �ִ� ���
			photo[i] = make_pair(student, order); //�ĺ� �߰�
			return false;
		}
	}
	return true;
}

//������ �ĺ��� �ε����� ã�� �Լ�
int deletePos(int n, map<int, int>& recommend_cnt, vector <pair<int, int>>& photo) {
	int pos = 0; //��õ���� ���� ���� �ĺ��� �ε���
	for (int i = 1; i < n; i++) {
		bool update = (recommend_cnt[photo[i].first] < recommend_cnt[photo[pos].first]) ||
			(recommend_cnt[photo[i].first] == recommend_cnt[photo[pos].first] && photo[i].second < photo[pos].second);
		if (update) //��õ���� ���ų�, �����鼭 �� ���� �Խõ� ������ ���
			pos = i;
	}
	return pos;
}

//���� �ĺ� ���ϴ� �Լ�
vector<int> candidateList(int n, int num, vector<int> student_list) {
	vector<pair<int, int>> photo; //����Ʋ(�ĺ�, ����)
	map<int, int> recommend_cnt;
	photo.assign(n, { 0,0 }); //�ʱ�ȭ

	for (int i = 0; i < num; i++) {
		int student = student_list[i];
		recommend_cnt[student]++;
		if (isFull(n, student, i, photo)) { //���� �Խõ��� �ʾҴµ� ����Ʋ�� �� �� ���
			int pos = deletePos(n, recommend_cnt, photo); //�ٲ� ����Ʋ ��ġ
			recommend_cnt[photo[pos].first] = 0; //��õ�� �ʱ�ȭ
			photo[pos] = make_pair(student, i); //���� �ٲٱ�
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if(photo[i].first >0)
			ans.push_back(photo[i].first);
	}
	
	return ans;
}

int main() {
	int n, num, student;
	vector<int> student_list;

	//�Է�
	cin >> n >> num;
	student_list.assign(num, 0);
	for(int i=0; i<num; i++) {
		cin >> student_list[i];
	}

	//����
	vector<int> ans = candidateList(n, num, student_list);
	sort(ans.begin(), ans.end());

	//���
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}