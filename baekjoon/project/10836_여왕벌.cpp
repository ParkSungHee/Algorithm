#include<iostream>
#include<vector>
using namespace std;

int m, n, num0, num1, num2;
vector<int> grow;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    grow.resize(2 * m - 1, 1);

    while (n--) {
        cin >> num0 >> num1 >> num2;

        for (int i = num0; i < num0 + num1; i++) {
            grow[i] += 1;
        }
        for (int i = num0 + num1; i < 2 * m - 1; i++) {
            grow[i] += 2;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                cout << grow[m - i - 1] << " "; //3,2,1,0
            } else {
                cout << grow[m + j - 1] << " "; //4,5,6
            }
        }
        cout << "\n";
    }

    return 0;
}