#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	int h,m,s;
	h = a / 3600;
	a %= 3600;
	m = a / 60;
	a %= 60;
	s = a;
	printf("%d시간 %d분 %d초\n", h, m, s);
	return 0;
}