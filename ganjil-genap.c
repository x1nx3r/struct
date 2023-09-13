#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char* checkOdd(int num1){
    if (num1 % 2 == 0){
        return "even";
    } else{
        return "odd";
    }
}

void checkOdd_void(int num1){
    if (num1 % 2 == 0){
        printf("is even");
    } else {
        printf("is odd");
    }
}

bool checkEven(int num1){
    if (num1 % 2 == 0){
        return true;
    } else {
        return false;
    }
}

int main (){
    printf("3 adalah %s\n", checkOdd(3));

    printf("3 adalah");
    checkOdd_void(3);
}