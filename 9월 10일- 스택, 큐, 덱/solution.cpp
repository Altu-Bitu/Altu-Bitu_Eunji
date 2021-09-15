#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int temp = 0; //크레인으로 집은 인형
    stack<int> dolls; //인형을 담을 바구니

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            //moves[i] 위치에서 제일 위쪽에 있는 인형을 찾는다
            if (board[j][moves[i] - 1] != 0) {
                //인형을 가져오고 해당 위치에 0을 저장 후 안쪽 반복문 탈출
                temp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
            //moves[i] 위치에 인형이 없는 경우
            temp = 0;
        }

        //moves[i]에 인형이 없는 경우
        if (temp == 0)
            continue;
        //저장소가 비어있지 않고, 제일 위쪽 인형과 가져온 인형이 같은 경우
        if (!dolls.empty() && dolls.top() == temp) {
            dolls.pop();
            answer += 2;
        }
        else {
            dolls.push(temp);
        }

    }

    return answer;
}