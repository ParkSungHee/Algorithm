#include <iostream>
using namespace std;

void backtracking(int i, int j, int num) {
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << " ";
    } else {
        if (num / 3 == 0) { //��Ʈ��ŷ �ѹ� �� ���ص� ��
            cout << "*";
        } else {
            backtracking(i, j, num / 3); //�߰��� ����� �ϱ� ������
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