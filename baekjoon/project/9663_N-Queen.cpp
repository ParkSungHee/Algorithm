#include<iostream>
using namespace std;

/* 바킹독 youtube 참고 */ 

// y
// 0123456
// |||||||
bool y[40]; // column을 차지하고 있는지

// x+y
// 0123456
// /////// 왼쪽 하단부터 오른쪽 위까지 
bool add_xy[40]; // / 방향 대각선을 차지하고 있는지 => x+y가 같으면 / 같은 대각선

// x-y+n-1
// 6543210
// \\\\\\\  왼쪽 상단에서 오른쪽 하단까지
bool sub_xy[40]; // \ 방향 대각선을 차지하고 있는지 => x-y가 같으면 \ 같은 대각선
int cnt = 0;
int n;

void backtracking(int cur) { // cur번째 row에 말을 배치할 예정임 (y라고 생각)
    if (cur == n) { // N개를 놓는데 성공했다면 (한 줄에 하나)
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) { // (cur, i)에 퀸을 놓을 예정 (y,x)라고 생각 
        if (y[i] || add_xy[i + cur] || sub_xy[cur - i + n - 1]) // column이나 대각선 중에 문제가 있다면
            continue;
        y[i] = 1;
        add_xy[i + cur] = 1;
        sub_xy[cur - i + n - 1] = 1; //뒤에서부터 채우기
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