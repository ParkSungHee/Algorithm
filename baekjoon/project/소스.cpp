//1
//#include<stdio.h>
//
//int main() {
//		int arr[6][5] = { {1, 2, 3, 4, 5}, 
//						  {6, 7, 8, 9, 10}, 
//						  {11, 12, 13, 14, 15},
//						  {16, 17, 18, 19, 20}, 
//						  {21, 22, 23, 24, 25}, 
//						  {26, 27, 28, 29, 30} };
//		
//		for (int i = 5; i >= 0; i--) {
//			for (int j = 0; j < 5; j++) {
//				printf("%d ", *(*(arr + i) + j));
//			}
//			printf("\n");
//		}
//}

//2
//#include<stdio.h>
//#include<string.h>
//
//int main() {
//	char str1[20] = "coding";
//	char str2[10] = "computer";
//	char str3[10] = "hi";
//	printf("str1 문자열길이 : %d\n\n", strlen(str1));
//	
//	printf("str1 : %s\n", str1);
//	printf("str2 : %s\n", str2);
//	printf("strcpy 결과 : %s\n", strcpy(str1,str2));
//	printf("str1 : %s\n", str1);
//	printf("str2 : %s\n\n", str2);
//
//	printf("str1 : %s\n", str1);
//	printf("str3 : %s\n", str3);
//	printf("strcpy 결과 : %s\n", strncpy(str1, str3, 5));
//	printf("str1 : %s\n", str1);
//	printf("str3 : %s\n\n", str3);
//	
//}

//3
#include<stdio.h>

void sort(int n, int *a);

int main() 
{ 
    int n = 7; 
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 }; 
    sort(n, arr); 
	
	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr + i));
	}
	return 0; 
}

void sort(int n, int* a) {
	int temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (*(a + j) > *(a + j + 1)) {
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}