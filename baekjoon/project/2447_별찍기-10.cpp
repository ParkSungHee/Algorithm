#include <iostream>
using namespace std;

void backtracking(int i, int j, int num) {
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << " ";
    } else {
        if (num / 3 == 0) { //백트래킹 한번 더 안해도 됨
            cout << "*";
        } else {
            backtracking(i, j, num / 3); //중간에 비워야 하기 때문에
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            backtracking(i, j, n);
        }
        cout << "\n";
    }
}