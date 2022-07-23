#include <iostream>
using namespace std;

#define MAX 500002
int n, h, num;
int top[MAX];
int bottom[MAX];
int result[MAX];

int main() {
    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i % 2 == 1) {
            bottom[num]++;
        } else {
            top[h - num + 1]++;
        }
    }

    for (int i = h; i >= 1; i--) {
        bottom[i] += bottom[i + 1];
    }
    for (int i = 0; i < h; i++) {
        top[i + 1] += top[i];
    }

    int minSize = MAX, cnt;
    for (int i = 1; i <= h; i++) {
        result[i] = bottom[i] + top[i];
        if (result[i] < minSize) {
            minSize = result[i];
            cnt = 1;
        } else if (result[i] == minSize) {
            cnt += 1;
        }
    }

    cout << minSize << " " << cnt;

    return 0;
}