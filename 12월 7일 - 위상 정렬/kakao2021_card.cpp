//���� ��α�:https://kau-algorithm.tistory.com/151
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans = 1000;

int bfs(int r, int c, pair<int, int>card, vector<vector<int>>& board) { //(r,c): Ŀ���� ��ġ, card: ������(ī�� ��ġ)
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    queue<pair<pair<int, int>, int>> q; //(��ǥ, Ŀ�� �̵� Ƚ��)

    q.push({ {r, c},0 }); //�ʱ�ȭ
    visited[r][c] = true;

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (cr == card.first && cc == card.second) { //�������� �����ߴٸ�
            board[cr][cc] = 0; //ī�� ������
            return count + 1; //�̵� Ƚ�� ��ȯ
        }

        //�� ĭ�� �̵����� ���� ��ġ
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && !visited[nr][nc]) { //�ε����� ���� ���� �ְ� ���� �湮���� �ʾҴٸ�
                visited[nr][nc] = true;
                q.push({ { nr, nc }, count + 1 });
            }
        }

        //ctrl ������ �̵����� ���� ��ġ
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            while (nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && board[nr][nc] == 0) { //ī�带 ���� ������ ��ĭ�� �̵�
                nr += dr[i];
                nc += dc[i];
            }

            if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) { //���� ī�尡 ���� �ε��� ������ ����ٸ�
                nr -= dr[i];
                nc -= dc[i];
            }

            if (!visited[nr][nc]) { //���� �湮���� ���� ���̶��
                visited[nr][nc] = true;
                q.push({ { nr, nc }, count + 1 });
            }
        }
    }
}

void game(int row, int col, int cnt, int sum, vector<int> cards, vector<vector<int>> board) { //cnt: ������� ������ ī���� ��, sum: ������� Ŀ���� �̵� Ƚ��
    if (cnt == cards.size()) { //��� ī�带 �������ٸ�
        ans = min(ans, sum);
        return;
    }

    int cr1 = -1, cr2 = 0, cc1 = 0, cc2 = 0; //ī�� ��(1,2)�� ��ġ
    
    //ī�� ��ġ ã��
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == cards[cnt]) {
                if (cr1 < 0)
                    cr1 = i, cc1 = j;
                else
                    cr2 = i, cc2 = j;
            }
        }
    }

    //ī�� 1, ī�� 2 ������ ������
    int sum_to_2 = bfs(row, col, { cr1,cc1 }, board) + bfs(cr1, cc1, { cr2,cc2 }, board);

    //���� ��� ����� ���� �������� ī�� �ٽ� ������
    board[cr1][cc1] = cards[cnt];
    board[cr2][cc2] = cards[cnt];

    //ī�� 2, ī�� 1 ������ ������
    int sum_to_1 = bfs(row, col, { cr2,cc2 }, board) + bfs(cr2, cc2, { cr1,cc1 }, board);

    //���� ī�� ������
    game(cr2, cc2, cnt + 1, sum + sum_to_2, cards, board);
    game(cr1, cc1, cnt + 1, sum + sum_to_1, cards, board);
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1000;
    vector<bool>card_type(7, false);
    vector<int>cards;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] && !card_type[board[i][j]]) {
                card_type[board[i][j]] = true;
                cards.push_back(board[i][j]);
            }
        }
    }
    sort(cards.begin(), cards.end());

    do { //������ ���� ��� �õ�
        game(r, c, 0, 0, cards, board); //ù��° ī����� ������ ����
        answer = min(answer, ans); //game���� ���� ans�� ���Ͽ� �̵� Ƚ���� �� ������ ����
    } while (next_permutation(cards.begin(), cards.end()));

    return answer;
}

int main() {
    vector<vector<int>> board = { 
        {1,0,0,3},
        {2,0,0,0},
        {0,0,0,2},
        {3,0,1,0} };

    int r = 1, c = 0;
    
    //vector<vector<int>> board = {
    //   {1, 5, 0, 2},
    //   {6, 4, 3, 0},
    //   {0, 2, 1, 5},
    //   {3, 0, 6, 4} };

    //int r = 0, c = 0;

    cout << solution(board, r, c) << '\n';
}