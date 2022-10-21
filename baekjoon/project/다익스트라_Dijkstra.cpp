/*
 * Ư�� �ϳ��� �������� �ٸ� ��� �������� ���� �ִ� ��θ� �˷���
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 6, m, start;
#define INF 1e9
int a, b, c;
vector<pair<int, int>> graph[7]; //��� �� ����
int d[7]; //�ּ� ���

void dijkstra(int start) {  //��� ���� ���� ��, ���� �Ÿ��� ���� ������ �ϰ� ������ pq�� ���� ���� �ٲ����
    d[start] = 0;
    priority_queue<pair<int, int>> pq; //����� ������� ó���ϹǷ�
    pq.push({start, 0});

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second; //ª�� ���� ���� ������ ����ȭ
        pq.pop();

        cout << "cur: " << current << ", ���� �Ÿ�: " << d[current] << ", �ٲٷ��� �Ÿ�:  " << distance << endl;

        if (d[current] < distance) //�ִ� �Ÿ��� �ƴ� ���
            continue;

        for (auto &i: graph[current]) { //���õ� ����� ���� ���
            int next = i.first;
            int nextDistance = distance + i.second;
            cout << "next: " << next << ", " << nextDistance << "\n";

            if (nextDistance < d[next]) {    //������ �ּ� ��뺸�� �� �����ϴٸ� ��ü
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

    for (int i = 1; i <= n; i++) { //������� ���� ��� ����� ����
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

    // [ �Է¹޵��� �ϴ� �ڵ� ]
    //cin >> n >> m >> start; //��� ����, �������� ����, ���� ���
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