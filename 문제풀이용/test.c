#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int size, x, y, count = 0, sum = 0, avg = 0;

    scanf("%d %d", &x, &y);
    size = x * y;

    int* numPtr = malloc(sizeof(int) * size);    // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�

    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        int a = 0;
        scanf("%d", &a);
        numPtr[i] = a; // �ε����� �����Ͽ� �� �Ҵ�

        sum += a;
    }

    avg = sum / size;

    for (int i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
    {
        if (numPtr[i] >= avg) printf("%d ", numPtr[i]);    // �ε����� �����Ͽ� �� ���
        else printf("0 ");
        count++;

        if (count == y) {
            printf("\n");
            count = 0;
        }

    }



    free(numPtr);    // �������� �Ҵ��� �޸� ����

    return 0;
}