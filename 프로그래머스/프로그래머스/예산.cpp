#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int price = 0;
    int answer = 0;

    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        if (price + d[i] <= budget) {
            price += d[i];
            answer++;
        }
        else
            break;
    }

    return answer;
}

int main() {
    vector<int> d = { 2,2,3,3 };
    int budget = 10;
    cout << solution(d, budget);
}