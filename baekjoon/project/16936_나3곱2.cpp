#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long result = 0; //�����尳��*�����ڼ� �ִ��� 1,000,000 * 1,000,000 int���
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
            if (tester % c == 0) { //�� ������ ��
                result += (tester / c);
            } else {
                result += (tester / c) + 1;
            }
        }
    }
    cout << result;
    return 0;
}