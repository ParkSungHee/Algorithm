/*
 * Ư�� �ϳ��� �������� �ٸ� ��� �������� ���� �ִ� ��θ� �˷���
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;
vector<pair<int, int>> a[7]; //��� �� ����
int d[7]; //�ּ� ���

void dijkstra(int start) {
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

        for (auto &i: a[current]) { //���õ� ����� ���� ���
            int next = i.first;
            int nextDistance = distance + i.second;
            cout << "next: " << next << ", " << nextDistance << "\n";

            if (nextDistance < d[next]) {    //������ �ּ� ��뺸�� �� �����ϴٸ� ��ü
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

    for (int i = 1; i <= number; i++) { //������� ���� ��� ����� ����
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