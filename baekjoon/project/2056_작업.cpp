#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> edge[10003];
int in_degree[100003];
int t[100003];

int main() {
    int n, k, t_input, oper, result = 0; // t_input: ½Ã°£
    priority_queue<pair<int, int>> pq;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t_input >> k;
        t[i] = t_input;

        if (k == 0) {
            pq.push({-t_input, i});
        } else {
            while (k--) {
                cin >> oper;
                edge[oper].push_back(i);
                in_degree[i]++;
            }
        }
    }

    while (!pq.empty()) {
        int op_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();

        result = max(op_time, result);

        for (int next: edge[num]) {
            in_degree[next]--;
            if (!in_degree[next]) {
                int op = op_time + t[next];
                pq.push({-op, next});
            }
        }
    }

    cout << result;

    return 0;
}