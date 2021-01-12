#include <iostream>
#include <cmath> 
using namespace std;

/* ������� ���ӵ� ������ ��ܼ��� ���� �� */
// �������̳� �������� ������ �� ���� �濡 L��ŭ�� ���θ� ��ġ�� �� �ִ��� ? ������ ?
int n, L, row = 0, column = 0;
int map[100][100];

int main() {
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    //cnt = ������ +1, �������̸� cnt_row = 1 �ʱ�ȭ, �������̸� -(L-1)  
    //�� �˻� (���ӵ� �� ����, ������ ����ġ�ϸ� flag�� false)
    for (int i = 0; i < n; i++) {
        int cnt_row = 1;                    //��������� ���ӵ� ���� ������ ��� ��(���� ��ġ ���θ� ����)
        bool flag_row = true;               //���� ����� �ִ����� flag
        for (int j = 0; j < n - 1; j++) {
            if (map[i][j] == map[i][j + 1]) //1. ���̰� ���ٸ� 
                cnt_row++;                  //���ӵ� ���� ���� ��� �� ����
            else if (map[i][j] - map[i][j + 1] == -1) { //2. �������� ���
                if (cnt_row >= L) //���ݱ����� ���ӵ� ��ܼ��� ���θ� ���� �� ������ �������� ����
                    cnt_row = 1;  //���� �� �ִٸ� �ٽ� ���ӵ� ��ܼ��� 1
                else
                    flag_row = false; //���� �� ���ٸ� ���� ���� �� ����
            }
            else if (map[i][j] - map[i][j + 1] == 1) { //3. �������� ���
                if (cnt_row < 0)
                    flag_row = false; //���� ���̼��� ���� ��,�ʿ䰡 �� ������ �� ���ΰ� �ʿ��ϴ� ���� �Ұ��� ����̹Ƿ� �÷��� ǥ��
                else
                    cnt_row = -(L - 1); // ������ L-1���� ���� ���̼��� �ʿ��ϹǷ� 
            }
            else
                flag_row = false;//4. ���� ��ʸ� �����ϸ� ��� �Ұ�
        }
        if (cnt_row >= 0 && flag_row) {
            /*cout << "\n" << i << endl;*/
            row++;
        } //�̹� �Ұ�����(flag_row)�� �ʿ��� ���� ������ ��ܼ��� ��������� Ȯ��
    }

    //�� �˻� 
    for (int i = 0; i < n; i++) {
        int cnt_column = 1;
        bool flag_column = true;
        for (int j = 0; j < n - 1; j++) {
            if (map[j][i] == map[j + 1][i])
                cnt_column++;
            else if (map[j][i] - map[j + 1][i] == -1) {
                if (cnt_column >= L)
                    cnt_column = 1;
                else
                    flag_column = false;
            }
            else if (map[j][i] - map[j + 1][i] == 1) {
                if (cnt_column < 0)
                    flag_column = false;
                else
                    cnt_column = -(L - 1);
            }
            else
                flag_column = false;
        }
        if (cnt_column >= 0 && flag_column) {
            /*cout << "\n" << i << endl;*/
            column++;
        }
    }
    cout << row + column;

    return 0;
}