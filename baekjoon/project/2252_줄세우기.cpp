#include<iostream>
#include<queue>
using namespace std;

vector<int> edge[32002];
int n, m, in_degree[32002];
int a, b;
queue<int> q;

int main() {
    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        edge[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++) { //Indegree가 0인 정점을 q에 넣음
        if (!in_degree[i]) { //진입 차수 없는 경우
            q.push(i);
        }
    }

    while (!q.empty()) { //Indegree가 0인 정점을 q에 넣음
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int next: edge[now]) { //Indegree -1해주고 0이면 q에 넣음
            in_degree[next]--;
            if (!(in_degree[next])) {
                q.push(next);
            }
        }
    }

    return 0;
}