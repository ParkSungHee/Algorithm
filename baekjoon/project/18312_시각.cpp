#include <iostream>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) { //½Ã
        for (int j = 0; j < 60; j++) { //ºÐ
            for (int z = 0; z < 60; z++) { //ÃÊ
                if (i % 10 == k || i / 10 == k ||
                    j % 10 == k || j / 10 == k ||
                    z % 10 == k || z / 10 == k) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}