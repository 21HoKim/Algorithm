#include<stdio.h>
#include<stdbool.h>
bool array(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
int main() {

	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++) {
		if (array(i)&&i!=1) {
			printf("%d\n",i);
		}
		
	}
	return 0;
}