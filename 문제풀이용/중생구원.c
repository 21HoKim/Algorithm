#include<stdio.h>
int main() {
	int n = 0;
	int a, b = 1;
	int count = 0;
	scanf("%d", &a);
    if (1 > a || a > 9) {
        printf("1���� 9������ �� �߿��� �Է����ּ���.\n");
    }
    else {
        while (n != a) {
 
            if (10 <= n) {
                n =n % 10;
                n = n * 3;
                count++;
            }
            else {
                n = n * 3;
                count++;
            }
        }
    }
    printf("%d", count);
	return 0;
}