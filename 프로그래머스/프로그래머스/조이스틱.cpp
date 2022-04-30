////https://4z7l.github.io/2021/03/12/algorithms-prg-42860.html
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//int LUT[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//
//int solution(string name) {
//    int answer = 0;
//
//    for (char ch: name) {
//        answer += LUT[ch - 'A']; //�� ������ ���̽�ƽ ������ ����
//    }
//
//    //���� �̵��ϴ� �����ϱ� ���� ����
//    int len = name.size();
//    int left_right = len - 1;
//
//    for (int i = 0; i < len; i++) {
//        int next_i = i + 1; //���� ���� idx
//        while (next_i < len && name[next_i] == 'A') { //���̸� �����ʰ� 'A'�̸�
//            next_i++;
//        }
//        cout << "i: " << i << ", len: " << len << ", next_i: " << next_i << endl;
//        int m = min(i, len - next_i);
//        cout << "m: " << m << endl;
//
//        left_right = min(left_right, i + len - next_i + m);
//        cout << "left_right: " << left_right << endl;
//    }
//    answer += left_right;
//    return answer;
//}
//
//int main() {
//    string s = "BAB";
//    cout << solution(s);
//}