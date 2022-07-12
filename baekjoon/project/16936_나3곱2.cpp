#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long result = 0; //시험장개수*응시자수 최댓값이 1,000,000 * 1,000,000 int벗어남
    int testRoom, b, c, num;
    vector<int> testNum;

    cin >> testRoom;
    while (testRoom--) {
        cin >> num;
        testNum.push_back(num);
    }
    cin >> b >> c;

    for (auto tester: testNum) {
        tester -= b;

        if (tester <= 0) {
            result++;
        } else {
            result++;
            if (tester % c == 0) { //딱 떨어질 때
                result += (tester / c);
            } else {
                result += (tester / c) + 1;
            }
        }
    }
    cout << result;
    return 0;
}