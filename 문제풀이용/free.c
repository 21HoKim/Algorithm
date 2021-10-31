#include<stdio.h>
int main() {

    char str[21] = { 0 };
    int idx = 0;
    int c = 0;
    for (int i = 0; i < 20; i++) {
            scanf("%c", &str[idx++]);
            getchar();
            if (str[i] == '.') {
                break;
            }
            c++;
    }
    for (int i = 0; i < c; i++){
        printf("%c", str[i]);
    }
    return 0;
}