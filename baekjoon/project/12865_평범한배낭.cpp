#include<iostream>
#include<algorithm>
using namespace std;


int n, k;
int dp[101][100001];
int w[102], v[102];


int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) { // 물건 번호
        for (int j = 1; j <= k; j++) { // 무게
            if (w[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                int v1 = dp[i - 1][j];
                int v2 = dp[i - 1][j - w[i]] + v[i];

                dp[i][j] = max(v1, v2);
            }
        }
    }

    cout << dp[n][k];
    return 0;
}