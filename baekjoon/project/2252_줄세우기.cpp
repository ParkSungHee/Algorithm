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

    for (int i = 1; i <= n; i++) { //Indegree�� 0�� ������ q�� ����
        if (!in_degree[i]) { //���� ���� ���� ���
            q.push(i);
        }
    }

    while (!q.empty()) { //Indegree�� 0�� ������ q�� ����
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int next: edge[now]) { //Indegree -1���ְ� 0�̸� q�� ����
            in_degree[next]--;
            if (!(in_degree[next])) {
                q.push(next);
            }
        }
    }

    return 0;
}