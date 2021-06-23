#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int left, int right) {
    vector<int> v;
    int answer = 0;

    for (int i = left; i <= right; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                sum++;
            }
        }
        v.push_back(sum);
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            answer += (i+left);
        }
        else {
            answer -= (i + left);
        }
    }

    return answer;
}

int main() {
    int left = 13;
    int right = 17;
    cout << solution(left, right);
}