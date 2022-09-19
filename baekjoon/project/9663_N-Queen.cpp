#include<iostream>
using namespace std;

/* ��ŷ�� youtube ���� */ 
//����, �밢���� ��ġ�ϰ� �ִ��� �Ǵ��ϱ� ���� ������

//y(����)�� �� �࿡ �ϳ��� ������ �Ǳ� ������ �ʿ����

// x ������ ��
// 0123456
// ||||||| (����)
bool y[40]; // column�� �����ϰ� �ִ���

// 0123456
// /////// ���� �ϴܺ��� ������ ������ 
bool add_xy[40]; // / ���� �밢���� �����ϰ� �ִ��� => x+y�� ������ / ���� �밢�� !!

// x-y +n-1 ������ (=>�ε����� ������ ������ �ʱ� ���� n-1)
// 6543210
// \\\\\\\  ���� ��ܿ��� ������ �ϴܱ���
bool sub_xy[40]; // \ ���� �밢���� �����ϰ� �ִ��� => x-y�� ������ \ ���� �밢�� !!
int cnt = 0;
int n;

void backtracking(int cur) { // cur��° row�� ���� ��ġ�� ������ (x��� ����)
    if (cur == n) { // N���� ���µ� �����ߴٸ� (�� �ٿ� �ϳ�)
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) { // (cur, i)�� ���� ���� ���� (x , y)��� ����
        if (y[i] || add_xy[i + cur] || sub_xy[cur - i + n - 1]) // column�̳� �밢�� �߿� ������ �ִٸ�
            continue;
        y[i] = 1;
        add_xy[i + cur] = 1;
        sub_xy[cur - i + n - 1] = 1; //�ڿ������� ä���
        backtracking(cur + 1);
        y[i] = 0;
        add_xy[i + cur] = 0;
        sub_xy[cur - i + n - 1] = 0;
    }
}

int main(void) {

    cin >> n;

    backtracking(0);

    cout << cnt;
}