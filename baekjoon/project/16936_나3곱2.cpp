#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    long long num;
    vector<long long> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        vector<long long> vec;
        vec.push_back(v[i]);

        while (vec.size() < n) {
            bool isFlag = false; //vec�� ���� �� �ִ���

            // 2 ���ϱ�
            for (int j = 0; j < n; j++) {
                if ((vec.back() * 2) == v[j]) {
                    vec.push_back(v[j]);
                    isFlag = true;
                    break;
                }
            }
            // 3 ������
            if (!(vec.back() % 3)) {
                for (int j = 0; j < n; j++) {
                    if ((vec.back() / 3) == v[j]) {
                        vec.push_back(v[j]);
                        isFlag = true;
                        break;
                    }
                }
            }

            if (!isFlag) {
                break;
            }
        }
        if (vec.size() == n) {
            for (auto vv: vec) {
                cout << vv << " ";
            }
            break;
        }
    }
    return 0;
}