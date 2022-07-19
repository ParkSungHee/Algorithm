#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, num;

    cin >> n;
    vector<int> card(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        card.push_back(num);
    }
    sort(card.begin(), card.end());

    cin >> m;
    vector<bool> result(m);
    for (int i = 0; i < m; i++) {
        cin >> num;
        result[i] = binary_search(card.begin(), card.end(), num);
    }

    for (int r: result) {
        cout << r << " ";
    }

    return 0;
}