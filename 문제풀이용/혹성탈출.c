#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i, j, k, a;
    int free_count = 1;
    scanf("%d", &a);
    a++;
    int* testRoom = (int*)calloc(a, sizeof(int)); //a+1만큼 할당


    for (i = 2; i < a; i++) {
        if (testRoom[i] == 0) {
            free_count++;

            for (j = i, k = i; j <= a; j += k) {

                switch (testRoom[j]) {
                case 0:
                    testRoom[j] = 1;
                    break;
                case 1:
                    testRoom[j] = 0;
                    break;
                }

            }
        }
    }
    printf("%d", free_count);
    return 0;
}