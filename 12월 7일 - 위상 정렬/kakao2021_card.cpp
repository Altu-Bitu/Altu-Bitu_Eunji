//참고 블로그:https://kau-algorithm.tistory.com/151
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans = 1000;
vector<pair<pair<int, int>, pair<int, int>>> position(7);

int bfs(int r, int c, pair<int, int>card, vector<vector<int>>& board) { //(r,c): 커서의 위치, card: 목적지(카드 위치)
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    queue<pair<pair<int, int>, int>> q; //(좌표, 커서 이동 횟수)

    q.push({ {r, c},0 }); //초기화
    visited[r][c] = true;

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (cr == card.first && cc == card.second) { //목적지에 도달했다면
            board[cr][cc] = 0; //카드 뒤집기
            return count + 1; //이동 횟수 반환
        }

        //한 칸만 이동했을 때의 위치
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && !visited[nr][nc]) { //인덱스가 범위 내에 있고 아직 방문하지 않았다면
                visited[nr][nc] = true;
                q.push({ { nr, nc }, count + 1 });
            }
        }

        //ctrl 누르고 이동했을 때의 위치
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            while (nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && board[nr][nc] == 0) { //카드를 만날 때까지 한칸씩 이동
                nr += dr[i];
                nc += dc[i];
            }

            if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) { //끝에 카드가 없어 인덱스 범위를 벗어났다면
                nr -= dr[i];
                nc -= dc[i];
            }

            if (!visited[nr][nc]) { //아직 방문하지 않은 곳이라면
                visited[nr][nc] = true;
                q.push({ { nr, nc }, count + 1 });
            }
        }
    }
}

void game(int row, int col, int cnt, int sum, vector<int> cards, vector<vector<int>> board) { //cnt: 현재까지 뒤집은 카드의 수, sum: 현재까지 커서의 이동 횟수
    if (cnt == cards.size()) { //모든 카드를 뒤집었다면
        ans = min(ans, sum);
        return;
    }

    int cr1 = position[cards[cnt]].first.first, cc1 = position[cards[cnt]].first.second; //카드1의 위치
    int cr2 = position[cards[cnt]].second.first,  cc2 = position[cards[cnt]].second.second; //카드2의 위치

    //카드 1, 카드 2 순으로 뒤집음
    int sum_to_2 = bfs(row, col, { cr1,cc1 }, board) + bfs(cr1, cc1, { cr2,cc2 }, board);
    game(cr2, cc2, cnt + 1, sum + sum_to_2, cards, board); //다음 카드 뒤집기
   
    //다음 경우 계산을 위해 뒤집혀진 카드 다시 뒤집음
    board[cr1][cc1] = cards[cnt];
    board[cr2][cc2] = cards[cnt];

    //카드 2, 카드 1 순으로 뒤집음
    int sum_to_1 = bfs(row, col, { cr2,cc2 }, board) + bfs(cr2, cc2, { cr1,cc1 }, board);
    game(cr1, cc1, cnt + 1, sum + sum_to_1, cards, board); //다음 카드 뒤집기
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1000;
    vector<bool>card_type(7, false);
    vector<int>cards;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) { //카드가 있는 위치이면
                if (!card_type[board[i][j]]) { //입력받은 적 없는 카드 종류이면
                    card_type[board[i][j]] = true; //입력 받았음을 표시
                    cards.push_back(board[i][j]); //카드 목록에 추가
                    position[board[i][j]].first = { i,j }; //위치 저장
                }
                //이전에 입력받았던 종류의 카드라면
                position[board[i][j]].second = { i,j }; //위치만 저장
            }
        }
    }
    sort(cards.begin(), cards.end());

    do { //가능한 순서 모두 시도
        game(r, c, 0, 0, cards, board); //첫번째 카드부터 뒤집기 시작
        answer = min(answer, ans); //game에서 구한 ans와 비교하여 이동 횟수가 더 적으면 갱신
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