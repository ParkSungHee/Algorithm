/*
 * 특정 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줌
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 6, m, start;
#define INF 1e9
int a, b, c;
vector<pair<int, int>> graph[7]; //노드 간 간선
int d[7]; //최소 비용

void dijkstra(int start) {  //노드 순서 작은 것, 만약 거리를 작은 순으로 하고 싶으면 pq에 들어가는 순서 바꿔야함
    d[start] = 0;
    priority_queue<pair<int, int>> pq; //가까운 순서대로 처리하므로
    pq.push({start, 0});

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second; //짧은 것이 먼저 오도록 음수화
        pq.pop();

        cout << "cur: " << current << ", 현재 거리: " << d[current] << ", 바꾸려는 거리:  " << distance << endl;

        if (d[current] < distance) //최단 거리가 아닌 경우
            continue;

        for (auto &i: graph[current]) { //선택된 노드의 인접 노드
            int next = i.first;
            int nextDistance = distance + i.second;
            cout << "next: " << next << ", " << nextDistance << "\n";

            if (nextDistance < d[next]) {    //기존의 최소 비용보다 더 저렴하다면 교체
                pq.push({next, -nextDistance});
                d[next] = nextDistance;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= n; i++) { //연결되지 않은 경우 비용은 무한
        d[i] = INF;
    }

    graph[1].emplace_back(2, 2);
    graph[1].emplace_back(3, 5);
    graph[1].emplace_back(4, 1);

    graph[2].emplace_back(1, 2);
    graph[2].emplace_back(3, 3);
    graph[2].emplace_back(4, 2);

    graph[3].emplace_back(1, 5);
    graph[3].emplace_back(2, 3);
    graph[3].emplace_back(4, 3);
    graph[3].emplace_back(5, 1);
    graph[3].emplace_back(6, 5);

    graph[4].emplace_back(1, 1);
    graph[4].emplace_back(2, 2);
    graph[4].emplace_back(3, 3);
    graph[4].emplace_back(5, 1);

    graph[5].emplace_back(3, 1);
    graph[5].emplace_back(4, 1);
    graph[5].emplace_back(6, 2);

    graph[6].emplace_back(3, 5);
    graph[6].emplace_back(5, 2);

    dijkstra(1);

    // [ 입력받도록 하는 코드 ]
    //cin >> n >> m >> start; //노드 개수, 간선정보 개수, 시작 노드
    //for (int i = 1; i <= n; i++) {
    //    d[i] = INF;
    //}
    //while (m--) {
    //    cin >> a >> b >> c;
    //    graph[a].push_back({b, c});
    //}
    //dijkstra(start);

    for (int i = 0; i <= n; i++) {
        if (d[i] == INF) {
            cout << "INFINITY" << "\n";
        } else {
            cout << d[i] << "\n";
        }
    }
    return 0;
}
//6 11 1
//1 2 2
//1 3 5
//1 4 1
//2 3 3
//2 4 2
//3 2 3
//3 6 5
//4 3 3
//4 5 1
//5 3 1
//5 6 2