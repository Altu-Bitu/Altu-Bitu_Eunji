#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<vector<int>> ground; //��(��� ����)

//����ִ� ������ ���� ���ϴ� �Լ�
int cntTree(int n, int m, vector<vector<int>> &a, deque<tp> &trees) {
	int ans = m; //����ִ� ������ ����
	
	vector<vector<int>> dead(n + 1, vector<int>(n + 1, 0)); //���� ���� ������ ����
	deque<tp> birth; //���� ���� ���� ������ ��

	int dr[8] = { -1,-1,-1, 0, 0, 1, 1, 1 }; //���� ����
	int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	while (m--) {
		int age = get<0>(trees.front());
		int r = get<1>(trees.front());
		int c = get<2>(trees.front());
		trees.pop_front();

		//��(����)
		if (age > ground[r][c]) {  //������ ���̺��� ���� ����� �����ϴٸ�
			dead[r][c] += age / 2; //�߰��� ����� �翡 ������ 1/2�� ��ŭ �� �߰�
			ans--;
			continue;
		}
		
		ground[r][c] -= age;
		age++;
		trees.push_back({ age,r,c });
		
		
		//����(����)
		if (age % 5 != 0)
			continue;

		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
				birth.push_back({ 1,nr,nc });
				ans++;
			}
		}
	}

	//��� �߰�(����, �ܿ�)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			ground[i][j] += (a[i][j] + dead[i][j]);
	}

	//���� �� ������ trees ������ �߰�
	while (!birth.empty()) {
		tp new_tree = birth.front();
		birth.pop_front();
		trees.push_front(new_tree); //���̰� ���� ��Ƿ� �տ� �߰�
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, x, y, z;

	//�Է�
	cin >> n >> m >> k;
	ground.assign(n + 1, vector<int>(n + 1, 5)); //���� ����� ��
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0)); //1�⸶�� �߰��Ǵ� ����� ��
	deque<tp> trees;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}

	for(int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		trees.push_back({ z,x,y }); //����, ��ġ ���� �ֱ�
	}

	//����
	sort(trees.begin(), trees.end()); //���̼����� ����

	while (k--) { //k�� �ݺ�
		m = cntTree(n, m, a, trees);
	}

	cout << m << '\n';
}