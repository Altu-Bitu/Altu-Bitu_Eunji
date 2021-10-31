#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//응시자가 거리두기를 잘 지켜서 앉아 있는지 검사
bool bfs(int row, int col, vector<string>place) { //row, col: 응시자 위치
    queue<pair<int, int>> q; //탐색을 위한 큐
    vector<vector<int>> visited(5, vector<int>(5, 0)); //방문 및 맨해튼 거리 표시하기 위한 벡터(0: 미방문, 1~3: 응시자로부터의 맨해튼 거리 - 1)
    q.push(make_pair(row, col)); //초기화
    visited[row][col] = 1;
    while (!q.empty()) {
        int dr[4] = { -1, 1, 0, 0 }; //상,하,좌,우
        int dc[4] = { 0, 0, -1, 1 };
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
                else if (place[nr][nc] == 'O') { //빈 공간이라면
                    q.push(make_pair(nr, nc)); //큐에 담기
                    visited[nr][nc] = visited[cr][cc] + 1; //맨해튼거리 갱신
                }
            }
        }
    }
    return true;
}

//place: 검사하고 있는 대기실, row:그 중에서도 몇번째 행 검사하고 있는지
bool checkDistance(int row, vector<string> place) {
    for (int i = 0; i < 5; i++) {
        if (place[row][i] == 'P') { //해당 위치에 응시자가 앉아 있다면 bfs로 거리두기 지키고 있는지 확인
            if (!bfs(row, i, place)) // 거리두기를 지키고 있지 않다면
                return false; //false 반환
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1); 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { //대기실의 행마다 거리두기를 지키고 있는지 확인
            if (!checkDistance(j, places[i])) { //거리두기를 지키지 않고 있다면
                answer[i] = 0; //answer에 0 저장 후
                break; //반복문 탈출하여 다음 대기실 검사
            }
        }
    }
    return answer;
}