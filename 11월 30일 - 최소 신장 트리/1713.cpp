#include<iostream>
#include<vector>
#include <map>
#include<algorithm>

using namespace std;

//사진틀이 꽉 찼는지 확인하는 함수
bool isFull(int n, int student, int order, vector<pair<int, int>> &photo) {
	for (int i = 0; i < n; i++) {
		if (photo[i].first == student) //사진이 이미 게시된 경우
			return false;
		else if (photo[i].first == 0) { //비어있는 사진틀이 있는 경우
			photo[i] = make_pair(student, order); //후보 추가
			return false;
		}
	}
	return true;
}

//삭제할 후보의 인덱스를 찾는 함수
int deletePos(int n, map<int, int>& recommend_cnt, vector <pair<int, int>>& photo) {
	int pos = 0; //추천수가 가장 낮은 후보의 인덱스
	for (int i = 1; i < n; i++) {
		bool update = (recommend_cnt[photo[i].first] < recommend_cnt[photo[pos].first]) ||
			(recommend_cnt[photo[i].first] == recommend_cnt[photo[pos].first] && photo[i].second < photo[pos].second);
		if (update) //추천수가 낮거나, 같으면서 더 먼저 게시된 사진인 경우
			pos = i;
	}
	return pos;
}

//최종 후보 구하는 함수
vector<int> candidateList(int n, int num, vector<int> student_list) {
	vector<pair<int, int>> photo; //사진틀(후보, 순서)
	map<int, int> recommend_cnt;
	photo.assign(n, { 0,0 }); //초기화

	for (int i = 0; i < num; i++) {
		int student = student_list[i];
		recommend_cnt[student]++;
		if (isFull(n, student, i, photo)) { //아직 게시되지 않았는데 사진틀이 꽉 찬 경우
			int pos = deletePos(n, recommend_cnt, photo); //바꿀 사진틀 위치
			recommend_cnt[photo[pos].first] = 0; //추천수 초기화
			photo[pos] = make_pair(student, i); //사진 바꾸기
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

	//입력
	cin >> n >> num;
	student_list.assign(num, 0);
	for(int i=0; i<num; i++) {
		cin >> student_list[i];
	}

	//연산
	vector<int> ans = candidateList(n, num, student_list);
	sort(ans.begin(), ans.end());

	//출력
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}