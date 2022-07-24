/*
 * 특정 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줌
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;
vector<pair<int, int>> a[7]; //노드 간 간선
int d[7]; //최소 비용

void dijkstra(int start) {
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

        for (auto &i: a[current]) { //선택된 노드의 인접 노드
            int next = i.first;
            int nextDistance = distance + i.second;
            cout << "next: " << next << ", " << nextDistance << "\n";

            if (nextDistance < d[next]) {    //기존의 최소 비용보다 더 저렴하다면 교체
                pq.push({next, -nextDistance}); //
                d[next] = nextDistance;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= number; i++) { //연결되지 않은 경우 비용은 무한
        d[i] = INF;
    }

    a[1].emplace_back(2, 2);
    a[1].emplace_back(3, 5);
    a[1].emplace_back(4, 1);

    a[2].emplace_back(1, 2);
    a[2].emplace_back(3, 3);
    a[2].emplace_back(4, 2);

    a[3].emplace_back(1, 5);
    a[3].emplace_back(2, 3);
    a[3].emplace_back(4, 3);
    a[3].emplace_back(5, 1);
    a[3].emplace_back(6, 5);

    a[4].emplace_back(1, 1);
    a[4].emplace_back(2, 2);
    a[4].emplace_back(3, 3);
    a[4].emplace_back(5, 1);

    a[5].emplace_back(3, 1);
    a[5].emplace_back(4, 1);
    a[5].emplace_back(6, 2);

    a[6].emplace_back(3, 5);
    a[6].emplace_back(5, 2);

    dijkstra(1);

    for (int i = 1; i <= number; i++) {
        cout << d[i] << " ";
    }

    return 0;
}