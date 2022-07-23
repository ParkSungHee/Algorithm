#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[5001];
bool visit[5001];
int answer = 0;

void bfs(int node, int cost) { // v k
    visit[node] = true;

    queue<pair<int, int>> q;
    q.push({node, cost});

    while (!q.empty()) {
        pair<int, int> nextNode = q.front();
        q.pop();

        for (auto x: tree[nextNode.first]) {
            if (cost <= x.second && !visit[x.first]) {
                q.push(x);
                visit[x.first] = true;
                answer += 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    int p, q, r, k, v;

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;

        tree[p].push_back({q, r});
        tree[q].push_back({p, r});
    }

    while (Q--) {
        answer = 0;
        memset(visit, 0, sizeof(visit));

        cin >> k >> v;
        bfs(v, k);
        cout << answer << "\n";
    }

    return 0;
}