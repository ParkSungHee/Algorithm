#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void dfs(int i, int sum, int target, vector<int> numbers) {
    if (sum == target && i == numbers.size()) {
        answer++;
        return;
    }
    else if (i < numbers.size()) {
        dfs(i + 1, sum + numbers[i], target, numbers);
        dfs(i + 1, sum - numbers[i], target, numbers);
    }
}


int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);

    return answer;
}

int main() {
    vector<int> number = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(number, target);

    return 0;
}