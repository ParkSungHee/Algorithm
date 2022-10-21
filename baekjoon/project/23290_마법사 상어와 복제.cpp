#include <iostream>
#include <vector>
using namespace std;

#define MAX 5
int smell[MAX][MAX]; // 물고기 냄새 - 2 : 냄새 생김 , 1: 냄새 남아있음
int m, s, fx, fy, d, sx, sy;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
struct Fish {
    int x, y;
    int d; // 방향
};
vector<Fish> fishs;
vector<Fish> copyMap[MAX][MAX]; //복제를 위한 임시 배열
vector<Fish> map[MAX][MAX];
int visit[4];

void clockwise() { // 반시계 방향

}

void mov(int x, int y) {
    vector<Fish> tmp[MAX][MAX];

    for (auto & m : map[x][y]) {
        int xx = m.x;
        int yy = m.y;
        int dir = m.d;
        bool isFlag = false;

        int nx, ny;
        for (int i = 0; i < 8; i++) {
            nx = xx + dx[(dir + i) % 8];
            ny = yy + dy[(dir + i) % 8];

            if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4) { //격자 밖 x
                if ((nx == sx && ny == sy) || smell[nx][ny] != 0) { //상어 or 물고기 냄새 x
                    isFlag = true;
                    break;
                }
            }
        }

        //이동
        if (isFlag) {
            tmp[nx][ny].push_back({nx, ny, dir});
        } else {
            tmp[xx][yy].push_back({xx, yy, dir});
        }
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            map[i][j] = tmp[i][j];
        }
    }
}

void load(int depth){
    if(depth == 3){

    }
    for(int i=1;i<=4;i++){
        visit[dep]
        load(depth+1);
    }
}

void sol() {
    //1. 복제
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    //2. 물고기 이동
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!map[i][j].empty()) {
                mov(i, j);
            }
        }
    }

    //3. 백트래킹 경로(중복순열) 찾기 - 상어 3칸 이동(물고기 많이 없애는 방법으로 이동, 격자범위 벗어나면 안됨)


    //4. 물고기 냄새 사라지게



    //5. 복제 완성
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            map[i][j].push_back(copyMap[i][j]);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> s;
    while (m--) {
        cin >> fx >> fy >> d;

        map[fx][fy].push_back({fx, fy, d});
    }
    cin >> sx >> sy;

    sol();

    //격자에 있는 물고기 수
    return 0;
}