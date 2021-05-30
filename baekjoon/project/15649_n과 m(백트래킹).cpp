#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visit[10];

void backtracking(int k) { // ���� k������ ���� ������.
    if (k == m) { // m���� ��� ��������
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr�� ����ص� ���� ���
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { // 1���� n������ ���� ����
        if (!visit[i]) { // ���� i�� ������ �ʾ�����
            arr[k] = i; // k��° ���� i�� ����
            visit[i] = 1; // i�� ���Ǿ��ٰ� ǥ��
            backtracking(k + 1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
            visit[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� ���� �������ʾҴٰ� �����.
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    backtracking(0);
}