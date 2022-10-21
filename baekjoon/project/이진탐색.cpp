#include <iostream>
#include <queue>
using namespace std;


int main() {
    vector<int> arr;
    int n, m, num;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    int start = 0, end = 1e9;
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long int total = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                total += arr[i] - mid;
            }
        }
        if (total < m) {
            end = mid - 1;
        } else {
            start = mid + 1;
            result = mid;
        }
    }
    cout << result;
    return 0;
}