/*
* 1주차 - BFS
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
더 이상 방문할 수 있는 점이 없는 경우 종료한다.
정점 번호는 1번부터 N번까지이다.
-------
입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000),
탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
입력으로 주어지는 간선은 양방향이다.
-------
출력
첫째 줄에 DFS를 수행한 결과를,
그 다음 줄에는 BFS를 수행한 결과를 출력한다.
V부터 방문된 점을 순서대로 출력하면 된다.
*/

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 1001			//N이 1~1000 이므로 1000번째 인덱스에 접근 -> 크기 1001까지 선언
int graph[MAX][MAX];		//인접행렬 배열로 간선을 나타냄
bool visit[MAX] = { 0, };	//visit 배열 default는 0으로
int N, M, V;

void DFS(int V) {
	visit[V] = 1;					//방문한 노드를 1로 변경(중복으로 방문 방지)
	cout << V << ' ';
	for (int i = 1; i <= N; i++) {	//모든 정점의 갯수
		if (graph[V][i] == 0 || visit[i] == 1) //graph 갈 수 없거나(간선x) 방문한 경우
			continue;
		DFS(i);									//간선이 존재하고 방문하지 않은 경우 ( 위 else )
	}
}
void BFS(int V) {
	queue<int> Q;
	Q.push(V);
	visit[V] = 1;
	while (!Q.empty()) {	//중복 방지
		V = Q.front();
		cout << Q.front() << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[V][i] == 1 && visit[i] == 0) {	//간선이 존재하고 방문하지 않은 경우
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
		graph[x][y] = graph[y][x] = 1;	//인접행렬표시
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

// x가 행, y가 열을 의미
//  		  x-1, y
//  x, y-1     x, y     x, y+1
//   		  x+1, y

int posx[4] = { 1,0,-1,0 };  //하 오 상 왼
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
			if (visit[nx][ny] || map[nx][ny] != 1)//벽이면
				continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return 0;
}

*/