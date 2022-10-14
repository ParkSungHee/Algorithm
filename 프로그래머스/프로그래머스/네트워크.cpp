#include <string>
#include <vector>
using namespace std;

int visit[201];

void dfs(int current, int n, vector<vector<int>> computers) {
    visit[current] = 1;

    for(int i=0;i<n;i++){
        if(!visit[i] && computers[current][i] == 1)
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(i, n, computers);
            cnt++;
        }
    }

    return cnt;
}