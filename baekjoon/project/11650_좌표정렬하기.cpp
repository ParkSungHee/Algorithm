#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int>p2){
    if(p1.first == p2.first){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, y;
    vector<pair<int, int>> v;

    cin >> n;
    while (n--) {
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end(), cmp);

    for(auto &i : v){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
