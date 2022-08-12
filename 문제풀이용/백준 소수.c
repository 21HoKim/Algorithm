#include<stdio.h>
#include<stdbool.h>
bool Dec(int a) {
	int count = 0;
	if (a == 1) {
		return false;
	}
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			count++;
		}
		if (count != 0) {
			return false;
		}
	}
	return true;
}
int DecSum(int M, int N) {
	int sum = 0;
	for (int i = M; i <= N; i++) {
		if (Dec(i)) {
			sum += i;
		}
	}
	return sum;
}
int DecMin(int M, int N) {
	int min = 50000;
	for (int i = M; i <= N; i++) {
		if (Dec(i)) {
			if (i < min) {
				min = i;
			}
		}
	}
	return min;
}
int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	int decsum = DecSum(M, N);
	if (decsum != 0) {
		printf("%d\n%d\n", decsum, DecMin(M, N));
	}
	else {
		printf("-1\n");
	}
	//int count = 0;
	//for (int i = 1; i <= 10000; i++) {
	//	//if(Dec(i))count++;
	//	if (Dec(i)) {
	//		printf("%d\n", i);
	//	}
	//}
	//printf("count : %d\n", count);
	return 0;
}