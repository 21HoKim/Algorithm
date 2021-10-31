#include<stdio.h>
int main() {
	int n = 0;
	int a, b = 1;
	int count = 0;
	scanf("%d", &a);
    if (1 > a || a > 9) {
        printf("1에서 9사이의 수 중에서 입력해주세요.\n");
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