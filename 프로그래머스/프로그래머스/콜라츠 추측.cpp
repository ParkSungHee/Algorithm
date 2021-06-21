#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    int answer = 0;

    for (int i = 0; num != 1; i++) {
        answer = i + 1;
        if (answer == 500) {
            return -1;
        }
        if (num % 2 == 0) {
            num /= 2;
        }
        else if (num % 2 == 1) {
            num = num * 3 + 1;
        }
    }
    return answer;
}
int main() {
    int n = 626331;
    cout << solution(n);
}