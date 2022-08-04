#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int t, f;
string s1, s2;
unordered_map<string, string> um;
unordered_map<string, int> res;

string Find(string s) {
    if (s == um[s]) {
        return s;
    }
    return um[s] = Find(um[s]);
}

void Union(string v1, string v2) {
    v1 = Find(v1);
    v2 = Find(v2);

    if (v1 != v2) {
        um[v2] = v1;
        res[v1] += res[v2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> f;

        um.clear();
        res.clear();
        while (f--) {
            cin >> s1 >> s2;

            if (um.count(s1) == 0) {
                um.insert({s1, s1});
                res.insert({s1, 1});
            }
            if (um.count(s2) == 0) {
                um.insert({s2, s2});
                res.insert({s2, 1});
            }

            Union(s1, s2);
            cout << res[Find(s1)] << "\n";
        }
    }

    return 0;
}