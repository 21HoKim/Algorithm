#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	int r500, r100, r50, r10;
	r500 = a / 500;
	a %= 500;
	r100 = a / 100;
	a %= 100;
	r50 = a / 50;
	a%= 50;
	r10 = a / 10;
	printf("%d %d %d %d", r500, r100, r50, r10);
	return 0;
}