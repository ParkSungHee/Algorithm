#include <iostream>
using namespace std;

int dp[1001][10];

int main() {
    int n, result = 0;;

    cin >> n;

    for (int i = 0; i < 10; i++) { //길이, 끝나는 숫자
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }

    for (int i = 0; i < 10; i++) {
        result += dp[n][i];
    }

    cout << result % 10007;

    return 0;
}