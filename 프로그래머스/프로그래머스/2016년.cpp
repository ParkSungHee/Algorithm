//2016�� 1�� 1�� �ݿ���
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int date[12] = { 3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 };
string day[7] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

string solution(int a, int b) {
	string answer = ""; //����
	int remainder = 0;

	for (int i = 1; i < a; i++) {
		remainder += date[i-1];
	}
	remainder = (remainder + b) % 7;
	answer = day[remainder];
	return answer;
}

int main() {
	int a=5, b=24; //��, ��
	string s = solution(a, b);
	cout << s;
}