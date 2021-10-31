#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//�����ڰ� �Ÿ��α⸦ �� ���Ѽ� �ɾ� �ִ��� �˻�
bool bfs(int row, int col, vector<string>place) { //row, col: ������ ��ġ
    queue<pair<int, int>> q; //Ž���� ���� ť
    vector<vector<int>> visited(5, vector<int>(5, 0)); //�湮 �� ����ư �Ÿ� ǥ���ϱ� ���� ����(0: �̹湮, 1~3: �����ڷκ����� ����ư �Ÿ� - 1)
    q.push(make_pair(row, col)); //�ʱ�ȭ
    visited[row][col] = 1;
    while (!q.empty()) {
        int dr[4] = { -1, 1, 0, 0 }; //��,��,��,��
        int dc[4] = { 0, 0, -1, 1 };
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (visited[cr][cc] >= 3) //����ư �Ÿ��� 2 �̻��̸� ���� ��� Ž�� �� ��
            continue;
        for (int j = 0; j < 4; j++) { //�����¿�� Ž��
            int nr = cr + dr[j];
            int nc = cc + dc[j];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && visited[nr][nc] == 0) {
                if (place[nr][nc] == 'P') { //���� �����ڰ� �ɾ� �ִٸ� �Ÿ��α� ��Ű�� ���� ���̹Ƿ� false ��ȯ
                    return false;
                }
                else if (place[nr][nc] == 'O') { //�� �����̶��
                    q.push(make_pair(nr, nc)); //ť�� ���
                    visited[nr][nc] = visited[cr][cc] + 1; //����ư�Ÿ� ����
                }
            }
        }
    }
    return true;
}

//place: �˻��ϰ� �ִ� ����, row:�� �߿����� ���° �� �˻��ϰ� �ִ���
bool checkDistance(int row, vector<string> place) {
    for (int i = 0; i < 5; i++) {
        if (place[row][i] == 'P') { //�ش� ��ġ�� �����ڰ� �ɾ� �ִٸ� bfs�� �Ÿ��α� ��Ű�� �ִ��� Ȯ��
            if (!bfs(row, i, place)) // �Ÿ��α⸦ ��Ű�� ���� �ʴٸ�
                return false; //false ��ȯ
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1); 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { //������ �ึ�� �Ÿ��α⸦ ��Ű�� �ִ��� Ȯ��
            if (!checkDistance(j, places[i])) { //�Ÿ��α⸦ ��Ű�� �ʰ� �ִٸ�
                answer[i] = 0; //answer�� 0 ���� ��
                break; //�ݺ��� Ż���Ͽ� ���� ���� �˻�
            }
        }
    }
    return answer;
}