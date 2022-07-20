#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int num, const vector<int> &a) {
    int start = 0;
    int end = a.size() - 1;
    int mid;

    while (end >= start) {
        mid = (start + end) / 2;
        if (num == a[mid]) {
            return true;
        } else if (a[mid] > num) {
            end = mid - 1;
        } else if (a[mid] < num) {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    vector<int> a;


    cin >> n;
    while (n--) {
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());
    cin >> m;
    while (m--) {
        cin >> num;
        cout << binarySearch(num, a) << "\n";
    }

    return 0;
}