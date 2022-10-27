//https://kibbomi.tistory.com/183
#include <iostream>
#include <string>
using namespace std;

char map[3][3];
string input;

bool checkXWin() {
    bool result = false;
    for (int i = 0; i < 3; i++) {
        if (map[i][0] == 'X' && map[i][0] == map[i][1] && map[i][1] == map[i][2]) //가로
            result = true;
    }
    for (int i = 0; i < 3; i++) {
        if (map[0][i] == 'X' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) //세로
            result = true;
    }
    if (map[0][0] == 'X' && map[0][0] == map[1][1] && map[1][1] == map[2][2]) // 대각선 (\)
        result = true;
    if (map[0][2] == 'X' && map[0][2] == map[1][1] && map[1][1] == map[2][0]) // 대각선 (/)
        result = true;

    return result;
}
bool checkOWin() {
    bool result = false;
    for (int i = 0; i < 3; i++) {
        if (map[i][0] == 'O' && map[i][0] == map[i][1] && map[i][1] == map[i][2]) //가로
            result = true;
    }
    for (int i = 0; i < 3; i++) {
        if (map[0][i] == 'O' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) //세로
            result = true;
    }
    if (map[0][0] == 'O' && map[0][0] == map[1][1] && map[1][1] == map[2][2]) // 대각선 (\)
        result = true;
    if (map[0][2] == 'O' && map[0][2] == map[1][1] && map[1][1] == map[2][0]) // 대각선 (/)
        result = true;

    return result;
}

int main() {
    cin >> input;

    while (input != "end") {
        int onum = 0, xnum = 0;
        bool owin = false, xwin = false;

        for (int i = 0; i < 9; i++) {
            map[i / 3][i % 3] = input[i];
            if (input[i] == 'O')
                ++onum;
            else if (input[i] == 'X')
                ++xnum;
        }
        xwin = checkXWin();
        owin = checkOWin();

        if (xwin && !owin && xnum - onum == 1) { //x가 이기는 경우, x먼저 놓기 때문
            cout << "valid\n";
        } else if (!xwin && owin && xnum == onum) {//y가 이기는 경우, x먼저 놓기 때문
            cout << "valid\n";
        } else if (!xwin && !owin && xnum == 5 && onum == 4) { //비기는 경우
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
        cin >> input;
    }

    return 0;
}
//xxx
//00.
//xxx

//xox
//oxo
//xox

//oxo
//xox
//oxo

//xxo
//oox
//xox

//xo.
//ox.
//..x

//.xx
//x.x
//ooo

//x.o
//o..
//x..

//oox
//xxo
//oxo