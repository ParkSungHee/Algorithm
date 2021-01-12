#include <iostream>
#include <queue>
using namespace std;

int N, M;
int check[101][101]; // ���������κ����� �Ÿ� ǥ��
int visit[101][101]; // �湮ǥ��
char map[101][101]; // �̷�
int pos[4][2] = { {-1,0},
				  {1,0},
				  {0,-1},
				  {0,1} };	//�� �� �� ��

void BFS(int x, int y){
	visit[x][y] = 1; // �湮ǥ��

	queue<pair<int, int> > q; // ť ����
	q.push(make_pair(x, y)); // ������ �ֱ�

	while (!q.empty()){ // ť�� �����Ͱ� ����������
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); // ť �� �� ������ ����

		for (int i = 0; i < 4; i++){
			int next_x = x + pos[i][0];
			int next_y = y + pos[i][1];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M){ // �̷��� ����
				if (map[next_x][next_y] == '1' && visit[next_x][next_y] == 0){ // ���� �����ϰ� ������ �湮�ߴ����� ���� ���
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); // ť�� ������ �о�ֱ�
				}
			}
		}
	}
}

int main(void){
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	BFS(0, 0);
	cout << check[N - 1][M - 1] + 1; //0, 0���� �����ϸ� count�� 0 -> ���� 1

}