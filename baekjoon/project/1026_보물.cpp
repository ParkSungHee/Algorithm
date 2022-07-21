#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, num, sum = 0;
    vector<int> a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }

    for(int j=0;j<n;j++){
        cin >> num;
        b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    for(int i=0;i<n;i++){
        sum += a[i] * b[i];
    }

    cout << sum;
    return 0;
}