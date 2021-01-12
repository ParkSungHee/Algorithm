#include<iostream>
#include<string.h>
using namespace std;

int n;
int length;
char op[4] = { '+', '-', '*', '/' };
int symbol_int[4];
int* sel;

//���� ���� �ִ� ����
// = ����! / ������!
static void same_per(int idx, int st) {
	if (idx == n-1) {
		for (int i = 0; i < sizeof(sel); i++)
			cout << op[sel[i]]; //���⼭ ��ó���ϱ� !!
		cout << endl;
		return;
	}
	if (!symbol_int[idx]) //symbol_int�� 0�� ��
		same_per(idx + 1, 0); //�ٸ� ��ȣ�� �ٲ�
	else {
		symbol_int[idx] -= 1;
		for (int s = st; s < sizeof(sel); s++) { //sel size��ŭ
			if (sel[s] < 0) { //������ �ȵ�������
				sel[s] = idx; 
				same_per(idx, s + 1);
				sel[s] = -1;
			}
		}
		symbol_int[idx] += 1;
	}
}
int main() {
	int number[12]; //����� ���ڿ�

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
