/*
* 1���� - BFS
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�.
���� ��ȣ�� 1������ N�������̴�.
-------
�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000),
Ž���� ������ ������ ��ȣ V�� �־�����.
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�.
�Է����� �־����� ������ ������̴�.
-------
���
ù° �ٿ� DFS�� ������ �����,
�� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�.
V���� �湮�� ���� ������� ����ϸ� �ȴ�.
*/

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 1001			//N�� 1~1000 �̹Ƿ� 1000��° �ε����� ���� -> ũ�� 1001���� ����
int graph[MAX][MAX];		//������� �迭�� ������ ��Ÿ��
bool visit[MAX] = { 0, };	//visit �迭 default�� 0����
int N, M, V;

void DFS(int V) {
	visit[V] = 1;					//�湮�� ��带 1�� ����(�ߺ����� �湮 ����)
	cout << V << ' ';
	for (int i = 1; i <= N; i++) {	//��� ������ ����
		if (graph[V][i] == 0 || visit[i] == 1) //graph �� �� ���ų�(����x) �湮�� ���
			continue;
		DFS(i);									//������ �����ϰ� �湮���� ���� ��� ( �� else )
	}
}
void BFS(int V) {
	queue<int> Q;
	Q.push(V);
	visit[V] = 1;
	while (!Q.empty()) {	//�ߺ� ����
		V = Q.front();
		cout << Q.front() << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[V][i] == 1 && visit[i] == 0) {	//������ �����ϰ� �湮���� ���� ���
				Q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;	//�������ǥ��
	}
	//DFS(V);
	//memset(visit, 0, sizeof(visit));
	//cout << endl;
	BFS(V);
	return 0;
}

/*
bfs
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[100][100] = {0,};
bool visit[100][100];
int n = 7, m = 10;

// x�� ��, y�� ���� �ǹ�
//  		  x-1, y
//  x, y-1     x, y     x, y+1
//   		  x+1, y

int posx[4] = { 1,0,-1,0 };  //�� �� �� ��
int posy[4] = { 0,1,0,-1 };


int main() {
	queue<pair<int, int>>q;
	visit[0][0] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cout << cur.first << ", " << cur.second;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + posx[dir];
			int ny = cur.second + posy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visit[nx][ny] || map[nx][ny] != 1)//���̸�
				continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return 0;
}

*/