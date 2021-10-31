#include<stdio.h>
int main() {
    int n, n2, n3;//n2는 최대 가로,세로값 n3는 중간-1값
    printf("1보다 큰값을 입력하세요 : ");
    scanf("%d", &n);
    n2 = 3 + 2 * (n - 1); // 가로,세로최대값
    n3 = n2 / 2; //중간 -1값
    printf("n2=%d ,n3=%d\n", n2, n3);
    for (int i = 0; i < n2; i++) {
        if (i < n3) {
            for (int j = n - i; j > 0; j--) {//공백출력
                printf(" ");
            }
            for (int k = 1; k <= (i + 1); k++) {
                printf("#");
            }
        }
        else {
            for (int j = 0; j < i - n; j++) {
                printf(" ");
            }
            for (int k = n3 + 1 - (i - n); k >= 0; k--) {
                printf("#");
            }

        }
        printf("\n");
    }
    return 0;
}