#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, num;
    vector<int> v, op; //숫자들, 연산자 수
    int minNum = 1000000000, maxNum = -1000000000;

    cin >> n;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < 4; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            op.push_back(i);
        }
    }

    do {
        int sum = v[0];
        for (int i = 0; i < v.size() - 1; i++) {
            switch (op[i]) {
                case 0: // +
                    sum += v[i + 1];
                    break;
                case 1: // -
                    sum -= v[i + 1];
                    break;
                case 2: // *
                    sum *= v[i + 1];
                    break;
                case 3: // /
                    sum /= v[i + 1];
                    break;
            }
        }

        if (sum < minNum) { //최솟값
            minNum = sum;
        }
        if (sum > maxNum) { //최댓값
            maxNum = sum;
        }

    } while (next_permutation(op.begin(), op.end()));

    cout << maxNum << "\n" << minNum;
    return 0;
}
