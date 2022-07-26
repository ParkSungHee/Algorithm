#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    int n;
    vector<string> res;
    string s;

    cin>>n;
    while (n--) {
        cin >> s;
        if(find(res.begin(), res.end(), s) == res.end()){
            res.push_back(s);
        }
    }

    sort(res.begin(), res.end(), comp);

    for (auto &r: res) {
        cout << r << "\n";
    }

    return 0;
}