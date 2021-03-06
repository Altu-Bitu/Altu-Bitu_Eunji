#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 5;

//응시자가 거리두기를 잘 지켜서 앉아 있는지 검사
bool bfs(int row, int col, vector<string> &place) { //row, col: 응시자 위치
    queue<pair<int, int>> q; //탐색을 위한 큐
    vector<vector<int>> visited(5, vector<int>(SIZE, 0)); //방문 및 맨해튼 거리 표시하기 위한 벡터(0: 미방문, 1~3: 응시자로부터의 맨해튼 거리 - 1)
    q.push(make_pair(row, col)); //초기화
    visited[row][col] = 1;
    int dr[4] = { -1, 1, 0, 0 }; //상,하,좌,우
    int dc[4] = { 0, 0, -1, 1 };
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (visited[cr][cc] >= 3) //맨해튼 거리가 2 이상이면 다음 노드 탐색 안 함
            continue;
        for (int j = 0; j < 4; j++) { //상하좌우로 탐색
            int nr = cr + dr[j];
            int nc = cc + dc[j];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && visited[nr][nc] == 0) {
                if (place[nr][nc] == 'P') { //만약 응시자가 앉아 있다면 거리두기 지키지 않은 것이므로 false 반환
                    return false;
                }
                if (place[nr][nc] == 'O') { //빈 공간이라면
                    q.push(make_pair(nr, nc)); //큐에 담기
                    visited[nr][nc] = visited[cr][cc] + 1; //맨해튼거리 갱신
                }
            }
        }
    }
    return true;
}

//대기실에서 거리두기를 지키고 있는지 검사
bool checkDistance(vector<string> &place) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (place[i][j] == 'P') { //해당 위치에 응시자가 앉아 있다면 bfs로 거리두기 지키고 있는지 확인
                if (!bfs(i, j, place)) // 거리두기를 지키고 있지 않다면
                    return false; //false 반환
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(SIZE, 1);
    //대기실마다 거리두기를 지키고 있는지 검사해서 answer에 저장
    for (int i = 0; i < SIZE; i++)
        answer[i] = checkDistance(places[i]);

    return answer;
}

int main() {
    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    vector<int> ans = solution(places);
    for (int i = 0; i < SIZE; i++)
        cout << ans[i] << ' ';
}