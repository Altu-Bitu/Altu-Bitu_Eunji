#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int temp = 0; //ũ�������� ���� ����
    stack<int> dolls; //������ ���� �ٱ���

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            //moves[i] ��ġ���� ���� ���ʿ� �ִ� ������ ã�´�
            if (board[j][moves[i] - 1] != 0) {
                //������ �������� �ش� ��ġ�� 0�� ���� �� ���� �ݺ��� Ż��
                temp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
            //moves[i] ��ġ�� ������ ���� ���
            temp = 0;
        }

        //moves[i]�� ������ ���� ���
        if (temp == 0)
            continue;
        //����Ұ� ������� �ʰ�, ���� ���� ������ ������ ������ ���� ���
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