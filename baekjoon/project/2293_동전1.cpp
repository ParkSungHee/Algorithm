#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int dp[100001];
int value[100001];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) { // 물건 번호
        for (int j = value[i]; j <= k; j++) { // 가치
            dp[j] += dp[j - value[i]];
        }
    }

    cout << dp[k];
    return 0;
}