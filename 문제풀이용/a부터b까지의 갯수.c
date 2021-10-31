
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
	printf("%d개\n", count);
	printf("두 수의 중간값 : %d\n",(a+b)/2);
	return 0;
}