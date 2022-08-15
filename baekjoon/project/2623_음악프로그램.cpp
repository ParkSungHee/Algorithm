#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001
int in_degree[MAX];
vector<int> edge[MAX];
vector<int> res;

int main() {
    int n, m, pre, singer, num;

    cin >> n >> m;
    while (m--) {
        vector<int> tmp;
        cin >> singer;

        cin >> pre;
        singer--;
        while (singer--) {
            cin >> num;
            in_degree[num]++;
            edge[pre].push_back(num);
            pre = num;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        res.push_back(now);

        for (auto &i: edge[now]) {
            in_degree[i]--;
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
    }

    if (res.size() == n) {
        for (auto &i: res) {
            cout << i << "\n";
        }
    } else {
        cout << 0;
    }
    return 0;
}
