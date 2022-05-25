#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 50

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char value);
char pop();

int main() {
    int count=0;
    char str[MAX_STACK_SIZE+1];

    gets(str);

    char search_book;

    scanf("%c",&search_book);

    for(int i = 0 ; i < strlen(str);i++)
        push(str[i]);

    while (top!=-1){
        if(stack[top]==search_book){
            printf("%d %d",count,top+1);
            break;
        }
        pop();
        count++;
    }


}

void push(char value){
    stack[++top] = value;
}

char pop(){
    return stack[--top];
}