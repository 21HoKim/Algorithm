#include<stdio.h>
int main() {
	double i = 0.001;
	while (1) {
		if (i * i - 8.000000 * i + 15.000000 == 0.000000) {
			printf("%lf\n", i);
		}
		else {
			//printf("no=%lf\n", i);
			printf("T=%lf\n", i * i - 8.000000 * i + 15.000000);
		}
		i += 0.001;
		if (i > 10) {
			break;
		}
	}
	return 0;
}