#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char ex[]="evaluation";

    char ex1[4];
    strncpy(ex1, ex, sizeof(ex1) - 1); // Copy at most 4 characters
    ex1[sizeof(ex1) - 1] = '\0'; // Null-terminate ex1

    printf("%s", ex1);
    

    char ex3[6]="Hello";
    char ex4[6]="Hello";

    int cmp=strcmp(ex3, ex4);
    printf("\n%d",cmp);



    return 0;
    
}