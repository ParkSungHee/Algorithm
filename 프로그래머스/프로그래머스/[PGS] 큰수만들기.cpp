#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;

    for (int i = 0; i < number.size() - k; i++) { //�ڸ�����ŭ
        char c = '0';
        for (int j = idx + 1; j <= i + k; j++) { // i+k : ������
            cout << c <<", " << number[j] << endl;
            if (c < number[j]) {
                c = number[j];
                idx = j;
            }
        }
        cout <<"c : "<< c<< endl;
        answer += c;
    }
    return answer;
}

int main(){
    solution("1231234", 3);
    return 0;
}