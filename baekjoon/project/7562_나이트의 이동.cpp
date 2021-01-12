#include <iostream>
#include <queue>
using namespace std;

int a[301][301], c[301][301], d[301][301];
int cnt, t, u, uf, v, vf, I;
int dx[] = { -1,-2,-2,-1,1,2,2,1 }, dy[] = { -2,-1,1,2,2,1,-1,-2 };

void BFS(int i, int j) {
    queue < pair< int, int >> q;
    q.push(make_pair(i, j));
    c[i][j] = 1;
    while (!q.empty()) {
        //x = ��, y = ��
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {//����Ʈ�� �̵��� �� �ִ� 8���� üũ
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < I && 0 <= ny && ny < I) {//�̵��Ϸ��� ĭ�� ü������ ���� ���� �ִٸ�
                if (c[nx][ny] == 0) { //üũ�� �ȵǾ� �ִ��� Ȯ���ϰ� �̵��Ѵ�
                    q.push(make_pair(nx, ny));
                    c[nx][ny] = 1;
                    d[nx][ny] = d[x][y] + 1;//���� ��ġ�� ť�� �־��ְ� ��θ� 1�����ش�
                }
            }
        }
    }
}
int main() {
    cin >> t;
    while (t--){
        cin >> I;
        cin >> u >> v >> uf >> vf;
        a[u][v] = 1;
        a[uf][vf] = 2;
        BFS(u, v);
        cout << d[uf][vf] << '\n';
        cnt = 0;//56��° �� ������ �ʱ�ȭ���ִ� �뵵
        for (int i = 0; i < 301; i++)
            for (int j = 0; j < 301; j++){
                c[i][j] = 0;
                d[i][j] = 0;
            }
        a[u][v] = 0;
        a[uf][vf] = 0;
    }
}


// https://codecollector.tistory.com/267 