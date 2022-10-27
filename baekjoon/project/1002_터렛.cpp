//https://beginnerdeveloper-lit.tistory.com/13
#include <iostream>
#include <cmath>
using namespace std;

void distance(int x1, int y1, int r1, int x2, int y2, int r2) {
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    int sum = r1 + r2;
    int sub = abs(r1 - r2);

    if (d == 0 && r1 == r2) { //원이 일치하는 경우 무한대
        cout << "-1\n";
    } else if (sum == d || sub == d) { //내접, 외접
        cout << "1\n";
    } else if (sub < d && d < sum) { //두 점에서 만나는 경우
        cout << "2\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    int t, x1, y1, r1, x2, y2, r2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        distance(x1, y1, r1, x2, y2, r2);
    }

    return 0;
}