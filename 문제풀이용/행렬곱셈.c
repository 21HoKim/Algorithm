#include<stdio.h>
int A[100][100] = { 0 }; //��� A
int B[100][100] = { 0 }; //��� B
int C[100][100] = { 0 }; //����� ���� ���ο� ���
int main() {
    int N, M;
    int m, K; //m=M
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) { //��� A�Է�
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &m, &K);
    for (int i = 0; i < m; i++) { //��� B�Է�
        for (int j = 0; j < K; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int sum = 0;
            for (int m = 0; m < M; m++) {
                sum += A[i][m] * B[m][j];
            }
            C[i][j] = sum;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}