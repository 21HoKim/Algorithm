#include<stdio.h>
int main() {
    int n, n2, n3;//n2�� �ִ� ����,���ΰ� n3�� �߰�-1��
    printf("1���� ū���� �Է��ϼ��� : ");
    scanf("%d", &n);
    n2 = 3 + 2 * (n - 1); // ����,�����ִ밪
    n3 = n2 / 2; //�߰� -1��
    printf("n2=%d ,n3=%d\n", n2, n3);
    for (int i = 0; i < n2; i++) {
        if (i < n3) {
            for (int j = n - i; j > 0; j--) {//�������
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