#include <iostream>
#include <vector>
using namespace std;

#define MAX 5
int smell[MAX][MAX]; // ����� ���� - 2 : ���� ���� , 1: ���� ��������
int m, s, fx, fy, d, sx, sy;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
struct Fish {
    int x, y;
    int d; // ����
};
vector<Fish> fishs;
vector<Fish> copyMap[MAX][MAX]; //������ ���� �ӽ� �迭
vector<Fish> map[MAX][MAX];
int visit[4];

void clockwise() { // �ݽð� ����

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

            if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4) { //���� �� x
                if ((nx == sx && ny == sy) || smell[nx][ny] != 0) { //��� or ����� ���� x
                    isFlag = true;
                    break;
                }
            }
        }

        //�̵�
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
    //1. ����
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    //2. ����� �̵�
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!map[i][j].empty()) {
                mov(i, j);
            }
        }
    }

    //3. ��Ʈ��ŷ ���(�ߺ�����) ã�� - ��� 3ĭ �̵�(����� ���� ���ִ� ������� �̵�, ���ڹ��� ����� �ȵ�)


    //4. ����� ���� �������



    //5. ���� �ϼ�
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

    //���ڿ� �ִ� ����� ��
    return 0;
}