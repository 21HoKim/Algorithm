
#include<stdio.h>
int main() {
	int a, b;
	int count = 0;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (a != b) {
			count++;
		}
		else {
			break;
		}
	}		
	printf("%d��\n", count);
	printf("�� ���� �߰��� : %d\n",(a+b)/2);
	return 0;
}