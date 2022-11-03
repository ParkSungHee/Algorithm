#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++) { //자르는 단위
        int cnt = 1;
        string stand = s.substr(0, i);
        string result;

        for (int j = i; j < s.size(); j += i) {
            string ver = s.substr(j, i);

            if (stand != ver) {
                if (cnt > 1) {
                    result += to_string(cnt);
                }
                result += stand;
                stand = ver;
                cnt = 1;
            } else {
                cnt++;
            }
        }

        if (cnt > 1)
            result += to_string(cnt);
        result += stand;

        if(answer > result.size()){
            answer = (int)result.size();
        }
    }
    return answer;
}

int main() {
    string s = "ababcdcdababcdcd";
    cout << solution(s);
    return 0;
}