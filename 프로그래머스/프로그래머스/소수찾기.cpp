#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> s;
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            if(isPrime(num))
                s.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return s.size();
}

int main() {
    string numbers = "011";
    cout << solution(numbers);

    return 0;
}