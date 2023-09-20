#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char ex[]="Hello";
    printf("%s\n",ex);

    ex[0]='y';
    printf("%s", ex);

    return 0;
}