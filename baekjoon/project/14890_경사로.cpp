#include <iostream>
#include <cmath> 
using namespace std;

/* 현재까지 연속된 높이의 계단수를 세는 것 */
// 오르막이나 내리막을 만났을 때 낮은 길에 L만큼의 경사로를 설치할 수 있느냐 ? 없느냐 ?
int n, L, row = 0, column = 0;
int map[100][100];

int main() {
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    //cnt = 같으면 +1, 오르막이면 cnt_row = 1 초기화, 내리막이면 -(L-1)  
    //행 검사 (연속된 거 새고, 조건이 불일치하면 flag가 false)
    for (int i = 0; i < n; i++) {
        int cnt_row = 1;                    //현재까지의 연속된 같은 높이의 계단 수(경사로 설치 여부를 위함)
        bool flag_row = true;               //길을 만들수 있는지의 flag
        for (int j = 0; j < n - 1; j++) {
            if (map[i][j] == map[i][j + 1]) //1. 높이가 같다면 
                cnt_row++;                  //연속된 같은 높이 계단 수 증가
            else if (map[i][j] - map[i][j + 1] == -1) { //2. 오르막인 경우
                if (cnt_row >= L) //지금까지의 연속된 계단수가 경사로를 놓을 수 있을지 없을지를 결정
                    cnt_row = 1;  //놓을 수 있다면 다시 연속된 계단수는 1
                else
                    flag_row = false; //놓을 수 없다면 길을 만들 수 없다
            }
            else if (map[i][j] - map[i][j + 1] == 1) { //3. 내리막인 경우
                if (cnt_row < 0)
                    flag_row = false; //같은 높이수가 음수 즉,필요가 더 많은데 또 경사로가 필요하는 경우는 불가한 경우이므로 플레그 표시
                else
                    cnt_row = -(L - 1); // 앞으로 L-1개의 같은 높이수가 필요하므로 
            }
            else
                flag_row = false;//4. 위의 사례를 제외하면 모두 불가
        }
        if (cnt_row >= 0 && flag_row) {
            /*cout << "\n" << i << endl;*/
            row++;
        } //이미 불가한지(flag_row)와 필요한 같은 높이의 계단수가 충족됬는지 확인
    }

    //열 검사 
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