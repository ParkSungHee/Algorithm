#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {500, 100, 50, 10, 5, 1};

int solution(int n) {
    int cnt = 0;
    int remaining = 1000 - n;

    for (int i = 0; i < v.size() && remaining > 0; i++) {
        cnt += remaining / v[i];
        remaining %= v[i];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
    return 0;
}