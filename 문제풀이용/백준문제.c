#include <stdio.h>
int A(int a) {
    a += 10;
    return a;
}
int main(void) {
    int a;
    scanf("%d", &a);
    printf("%d\n", A(a));
    return 0;
}