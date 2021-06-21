#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int n, int m) {
    int mod = n % m;
    while (mod > 0) {
        n = m;
        m = mod;
        mod = n % m;
    }
    return m;
}

int lcm(int n, int m) {
    return (n * m) / gcd(n, m);
}


vector<int> solution(int n, int m) {
    vector<int> answer;

    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));

    return answer;
}

int main() {
    int n = 3;
    int m = 12;

    vector<int> answer = solution(n, m);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}