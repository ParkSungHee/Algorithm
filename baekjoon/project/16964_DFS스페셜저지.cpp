#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001
vector<int> map[MAX], input;
int check[MAX];
int mem[MAX];
vector<int> res;
int n, a, b;

bool cmp(const int &v1, const int &v2) {
    return mem[v1] < mem[v2];
}

void dfs(int x) {
    if (check[x]) {
        return;
    }
    check[x] = true;

    res.push_back(x);
    for (auto y: map[x]) {
        if (!check[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a;
        input.push_back(a);
        mem[a] = i;
    }

    for (int i = 1; i <= n; i++) {
        sort(map[i].begin(), map[i].end(), cmp);
    }
    dfs(1);

    if (res == input) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}