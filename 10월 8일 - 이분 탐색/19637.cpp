#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int>power;

//Īȣ ��Ī�ϴ� �Լ�
vector<string> findName(int m, map<int, string> name) {
	vector<string> names;
	for (int i = 0; i < m; i++) {
		//power[i] �̻��� ���� ó������ ������ ��ġ ��ȯ
		//upper bound�� ��� ��� ���� �Էµ� ��� �Ѵܰ� ���� Īȣ ��Ī��
		auto iter = name.lower_bound(power[i]); 
		names.push_back(iter->second);
	}
	
	return names;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	map<int, string> name;

	//�Է�
	cin >> n >> m;
	power.assign(m, 0);

	for (int i = 0; i < n; i++) {
		string value;
		int key;
		cin >> value >> key;
		if (name[key] == "")
			name[key] = value;
	}

	for (int i = 0; i < m; i++)
		cin >> power[i];

	//����
	vector<string> names = findName(m, name);

	//���
	for (int i = 0; i < m; i++)
		cout << names[i] << '\n';
}