#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
long long numbers[10000002] = { 0 };
bool Pnum(int n) { //�Ҽ� �Ǻ�
	for (int i = 2; i<=n/2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main(void) {
	
	long long  min,max;
    long long count = 0;
	//clock_t start, end;
	//start = clock();
	//min = 999999000000;
	//max = 1000000000000; //10�� 11�� 1��
    scanf("%lld %lld", &min, &max);
	for (long long i = 2; i * i <= max; i++) { //�ּ� ������4, �������� max���� �۰ų� ���� ������ �ݺ�
		//for (long long j = i * i; j <= max - min + 1; j++) { if (j % (i * i) == 0) { numbers[j] = 1; j += i * i - 1; } }
			for (long long j = i * i; j <= max - min+1; j += i * i) {
				//printf("[%d]\n", j);
				numbers[j] = 1;
			}
		
	}
	for (long long i = 1; i <= max-min+1; i++) {
		//printf("!\n");
		if (numbers[i] != 0)
			count++;
	}
	printf("count : %d\n", count);
	//end = clock();
	//double res = (end - start) / CLOCKS_PER_SEC;

	//printf("%lf\n", res); //76
	printf("%lld\n", max-min+1-count); 

	return 0;
}