#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int in_degree[1003];
int cost[1003];

int main() {
    int tc, n, k, w;
    int a, b;

    cin >> tc;
    while (tc--) {
        vector<vector<int>> edge;

        cin >> n >> k;
        edge.resize(n + 1);

        for (int &i: in_degree) {
            i = 0;
        }

        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }

        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            in_degree[b]++;
            edge[a].push_back(b);
        }

        cin >> w;

        priority_queue<pair<int, int>> pq; //�Ǽ� �Ϸ� �ð�, �ǹ� ��ȣ

        //push �� ��&top�� �� '-'��ȣ ���̱� (pq�̱� ������ ���� �� ū �� ��ȯ�ؼ�)
        for (int i = 1; i <= n; i++) {
            if (!in_degree[i]) {
                pq.push({-cost[i], i});
            }
        }

        while (!pq.empty()) {
            int end_time = -pq.top().first; //�Ǽ� �Ϸ� �ð�
            int num = pq.top().second;

            cout << "(1)end_time: " << end_time << ", num: " << num << endl;

            pq.pop();

            if (num == w) {
                cout << end_time << "\n";
                break;
            }
            for (int next: edge[num]) {
                if (!(--in_degree[next])) {
                    int next_end_time = end_time + cost[next];
                    cout << "time: "<< next_end_time << ", next: "<< next<<endl;
                    pq.push({-next_end_time, next});
                }
            }
        }
    }

    return 0;
}