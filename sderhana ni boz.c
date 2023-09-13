#include <stdio.h>

int tambah(int x, int y){
    return x+y;
    
}

int kali(int x, int y){
    return x*y;
}

int kurang(int x, int y){
    return x-y;
}

int main (){

    printf("3*5 adalah : %d\n", kali(3,5));
    printf("7+7 adalah : %d\n", tambah(7,7));
    printf("1-6 adalah : %d", kurang(1,6));

    return 0;
}
