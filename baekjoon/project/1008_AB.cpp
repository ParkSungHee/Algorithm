#include <iostream>
#include <vector>
using namespace std;

int main() {
    double a, b;

    cin >> a >> b;

    cout.precision(12);
    cout << fixed << a / b;

    return 0;
}