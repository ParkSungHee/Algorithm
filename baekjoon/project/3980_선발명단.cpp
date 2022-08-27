#include <iostream>
#include <cstring>
using namespace std;

#define MAX 11
int player[MAX][MAX];
bool visit[MAX];
int result;

//0~10에 대한 순열을 하고 0이 아닌 것에 대한 더하기
void backtracking(int cnt, int sum) {
    if (cnt == 11) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 11; i++) {
        if (!player[cnt][i])
            continue;
        if (!visit[i]) {
            visit[i] = true;
            backtracking(cnt + 1, sum + player[cnt][i]);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> player[i][j];
            }
        }
        memset(visit, false, sizeof(visit));
        result = 0;
        backtracking(0, 0);
        cout << result << "\n";
    }

    return 0;
}
