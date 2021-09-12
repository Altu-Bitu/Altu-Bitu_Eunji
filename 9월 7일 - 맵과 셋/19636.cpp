#include<iostream>

using namespace std;

struct diet_info {
	//섭취량, 활동대사량, 기간, 기초대사량 역치
	int intake, a_metabolism, day, t;
};


// 0을 반환하면 사망, 1을 반환하면 요요, 2를 반환하면 요요x
int isYoyo(int w, int intake, int i_metabolism) {
	if (w <= 0 || i_metabolism <= 0) return 0;

	if (intake > i_metabolism) return 1;
	else return 2;
}

//기초 대사량 고려
void diet(struct diet_info info, int w, int i_metabolism) {
	int i_metabolism_after = i_metabolism;
	int w1 = w, w2 = w; //기초 대사랑 변하지 않을 때의 체중, 변할 때의 체중 (다이어트 후)
	int yoyo1, yoyo2; //요요, 사망 여부 저장할 변수

	int total1 = info.intake - (info.a_metabolism + i_metabolism); //일일 섭취-일일 소비(기초 대사량 고정)
	int total2 = info.intake - (info.a_metabolism + i_metabolism_after); //일일 섭취-일일 소비(기초 대사량 변화)
	
	
	
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

	//요요 여부
	yoyo1 = isYoyo(w1, i_metabolism, i_metabolism);
	yoyo2 = isYoyo(w2, i_metabolism, i_metabolism_after);

	//기초 대사량 변화 없을 때의 결과 출력
	if (yoyo1 != 0)
		cout << w1 << ' ' << i_metabolism << '\n';
	else
		cout << "Danger Diet\n";

	//기초 대사량 변화 있을 때의 결과 출력
	if (yoyo2 == 0)
		cout << "Danger Diet\n";
	if (yoyo2 == 1)
		cout << w2 << ' ' << i_metabolism_after << " YOYO";
	if (yoyo2 == 2)
		cout << w2 << ' ' << i_metabolism_after << " NO";

	
}



int main() {
	int w; //체중(다이어트 전,후)
	int i_metabolism; //기초대사량(다이어트 전,후)
	struct diet_info info; //다이어트 관련 정보

	//입력
	cin >> w >> i_metabolism >> info.t
		>> info.day >> info.intake >> info.a_metabolism;

	//출력
	diet(info, w, i_metabolism);
}