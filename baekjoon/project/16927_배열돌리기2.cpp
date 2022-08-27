#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 302
int arr[MAX][MAX];
int n, m, r;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate(int i1, int j1, int i2, int j2) {
    queue<int> q;
    int k = 2 * (i2 - i1 + j2 - j1);// 원소의 개수
    int num = r % k;//회전시킬 횟수
    int s = k - num;//큐 푸시엔팝 몇번할래?

    // enqueue
    for (int i = i1; i <= i2; i++) {
        q.push(arr[i][j1]);
    }
    for (int i = j1 + 1; i <= j2; i++) {
        q.push(arr[i2][i]);
    }
    for (int i = i2 - 1; i >= i1; i--) {
        q.push(arr[i][j2]);
    }
    for (int i = j2 - 1; i > j1; i--) {
        q.push(arr[i1][i]);
    }

    while (s--) {
        q.push(q.front());
        q.pop();
    }

    for (int i = i1; i <= i2; i++) {
        arr[i][j1] = q.front();
        q.pop();
    }
    for (int i = j1 + 1; i <= j2; i++) {
        arr[i2][i] = q.front();
        q.pop();
    }
    for (int i = i2 - 1; i >= i1; i--) {
        arr[i][j2] = q.front();
        q.pop();
    }
    for (int i = j2 - 1; i > j1; i--) {
        arr[i1][i] = q.front();
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int i1 = 0, j1 = 0, i2 = n - 1, j2 = m - 1;
    while (i1 < i2 && j1 < j2) {
        rotate(i1, j1, i2, j2);
        i1++, j1++, i2--, j2--;
    }
    print();
    return 0;
}
