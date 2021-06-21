#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 하샤드 수: 자릿수의 합으로 나누어지는 것
bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int tmp = x;
    
    do {
        sum += (tmp % 10);
        tmp /= 10;
    } while (tmp > 0);

    if ((x % sum) != 0) {
        answer = false;
    }
    return answer;
}

int main() {
    int arr = 11;
    bool result = solution(arr);
    cout << result;
}