#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001
int n, m;
int in_degree[MAX];
vector<int> edge[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        in_degree[b]++;
        edge[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int v = pq.top();
        cout << v << " ";
        pq.pop();

        for (auto next: edge[v]) {
            in_degree[next]--;
            if(in_degree[next] == 0){
                pq.push(next);
            }
        }
    }

    return 0;
}