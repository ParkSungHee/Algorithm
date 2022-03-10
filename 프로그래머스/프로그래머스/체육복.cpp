#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 1번 풀이
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> flag(n);
    bool isErase;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto i = lost.begin(); i != lost.end();) {
        isErase = false;

        for (auto j = reserve.begin(); j != reserve.end(); j++) {
            if (*i == *j) {
                lost.erase(i);
                reserve.erase(j);
                isErase = true;
                break;
            }
        }
        if (isErase == false) {
            ++i;
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        flag[lost[i] - 1] = 1; // 잃어버린 사람
    }
    for (int j = 0; j < reserve.size(); j++) {
        flag[reserve[j] - 1] = 2; //여벌의 체육복 가져온 사람
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (flag[i] == 1) {
                if (flag[i + 1] == 2) {
                    flag[i] = 0;
                    flag[i + 1] = 0;
                    continue;
                }
            }
        } else if (i == n - 1) {
            if (flag[i] == 1) {
                if (flag[i - 1] == 2) {
                    flag[i] = 0;
                    flag[i - 1] = 0;
                    break;
                }
            }
        } else {
            if (flag[i] == 1) {
                if (flag[i - 1] == 2) {
                    flag[i] = 0;
                    flag[i - 1] = 0;
                    continue;
                } else if (flag[i + 1] == 2) {
                    flag[i] = 0;
                    flag[i + 1] = 0;

                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (flag[i] == 0 || flag[i] == 2) {
            answer++;
        }
    }
    return answer;
}

// 2번 풀이
int sol(int n, vector<int> lost, vector<int> reserve) { //전체, 안가져온, 여벌
    vector<int> result(35);
    int r = 0;

    for (int i = 0; i < n; i++) { //전체 학생 1로 초기화
        result[i] = 1;
    }

    for (int i = 0; i < reserve.size(); i++) {  //여벌의 학생 번호에 2로
        result[reserve[i] - 1] = 2;
    }

    for (int i = 0; i < lost.size(); i++) {  // 도난 당한 학생 1로, 안가져온 학생 0으로
        if (result[lost[i] - 1] == 2) {
            result[lost[i] - 1] = 1;
        } else {
            result[lost[i] - 1] = 0;
        }
    }

    for (int i = 0; i < n; i++) { //안가져온 학생의 앞뒤에 여벌 학생이 있는지 보기
        if (i == 0) { // 첫 학생
            if (result[i] == 0) {
                if (result[i + 1] == 2) {
                    result[i] = 1;
                    result[i + 1] = 1;
                    continue;
                }
            }
        } else if (i == n - 1) { //마지막 학생
            if (result[i] == 0) {
                if (result[i - 1] == 2) {
                    result[i] = 1;
                    result[i - 1] = 1;
                    break;
                }
            }
        } else { //중간 학생
            if (result[i] == 0) {
                if (result[i - 1] == 2) { //앞에 여벌?
                    result[i] = 1;
                    result[i - 1] = 1;
                    continue; //이 부분 중요 !!
                } else if (result[i + 1] == 2) { //뒤에 여벌?
                    result[i] = 1;
                    result[i + 1] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (result[i] == 1 || result[i] == 2) {
            r++;
        }
    }

    return r;
}

int main() {
    int n = 7;
    vector<int> lost = {2, 4, 5, 6};
    vector<int> reserve = {1, 3, 6};
    int result = solution(n, lost, reserve);
    cout << result;
}