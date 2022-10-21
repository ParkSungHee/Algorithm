//https://blog.encrypted.gg/306
#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> coin[105];
bool D[50004]; // D[i] : i원을 만드는 것이 가능한지.

int main() {
    for (int t = 0; t < 3; t++) {
        //초기화
        for (int i = 0; i <= 50000; i++)
            D[i] = false;
        D[0] = true;

        cin >> N;
        int tot = 0;
        for (int i = 0; i < N; i++) {
            cin >> coin[i].first >> coin[i].second;
            tot += coin[i].first * coin[i].second;
        }
        if (tot % 2 == 1) {
            cout << 0 << "\n";
            continue;
        }
        sort(coin, coin + N);

        for (int i = 1; i <= coin[0].second; i++) {
            if (coin[0].first * i > tot / 2)
                break;
            D[i * coin[0].first] = true;
        }
        if (D[tot / 2]) { //반으로 나누는 것 가능
            cout << 1 << "\n";
            continue;
        }

        for (int i = 1; i < N; i++) {
            for (int j = tot / 2; j >= 0; j--) {
                if (!D[j])
                    continue;
                for (int k = 1; k <= coin[i].second; k++) {
                    if (j + k * coin[i].first > tot / 2)
                        break;
                    D[j + k * coin[i].first] = true;
                }
                if (D[tot / 2])
                    break;
            }
            if (D[tot / 2])
                break;
        }
        cout << D[tot / 2];
    }
}