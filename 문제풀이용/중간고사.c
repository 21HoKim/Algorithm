#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	if (a < 1) {
		printf("-1\n");
	}
	else {
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}