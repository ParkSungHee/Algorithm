#include<iostream>
#include<string.h>
using namespace std;

int n;
int length;
char op[4] = { '+', '-', '*', '/' };
int symbol_int[4];
int* sel;

//같은 것이 있는 순열
// = 순열! / 같은것!
static void same_per(int idx, int st) {
	if (idx == n-1) {
		for (int i = 0; i < sizeof(sel); i++)
			cout << op[sel[i]]; //여기서 일처리하기 !!
		cout << endl;
		return;
	}
	if (!symbol_int[idx]) //symbol_int가 0일 때
		same_per(idx + 1, 0); //다른 기호로 바꿈
	else {
		symbol_int[idx] -= 1;
		for (int s = st; s < sizeof(sel); s++) { //sel size만큼
			if (sel[s] < 0) { //지정이 안돼있으면
				sel[s] = idx; 
				same_per(idx, s + 1);
				sel[s] = -1;
			}
		}
		symbol_int[idx] += 1;
	}
}
int main() {
	int number[12]; //계산할 숫자열

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		number[i] = num;
	}

	sel = new int[n-1];


	for (int i = 0; i < 4; i++) {
		int sb;
		cin >> sb;

		symbol_int[i] = sb;
	}
	memset(sel, -1, sizeof(sel));

	same_per(0, 0);

	return 0;
	
}
