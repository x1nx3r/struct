/*

    Nama : Muhammad Mega Nugraha
    NPM : 22081010213

    TUGAS 2 Pemrograman Lanjut
    Soal :
    1. fungsi perpangkatan (void dan return value)
    2. fungsi penggabung nama depan dan nama belakang (void dan return value)
    3. fungsi cek validitas sebuah password: jika syarat password harus mengandung karakter ! dan minimal 8 karakter (void dan return value)
*/

#include<stdio.h>   
#include<string.h>  //Module untuk fungsi manipulasi string
#include<stdlib.h> 
#include<stdbool.h> //Module untuk fungsi manipulasi boolean


//  Soal 1 : Perpangkatan dua angka

// Fungsi perpangkatan dengan return value
int perpangkatan(int angka, int pangkat){
    int temp=1;
    for (int i=1;i<=pangkat;i++){
        temp=temp*angka;
    }
    return temp;
}

// Fungsi perpangkatan void
void perpangkatan_void(int angka, int pangkat){
    int temp=1;
    for (int i=1;i<=pangkat;i++){
        temp=temp*angka;
    }
    printf("\nVoid_%d\n", temp);
}


// SOAL 2 : Fungsi menggabung nama depan dan belakang

// Fungsi gabung nama dengan return
char* gabung_nama(const char* depan, const char* belakang){
    //hitung dulu total panjang keduanya
    int totalLen = strlen(depan) + strlen(belakang) + 1; // +1 adalah untuk null terminator

    //alokasi memori untuk string return
    char* digabung = (char*)malloc(totalLen*sizeof(char));
    if (digabung == NULL){
        perror("Alokasi memori gagal");
        exit(1);
    }
    
    strcpy(digabung, depan);
    strcat(digabung, " ");
    strcat(digabung, belakang);
    
    return digabung;
}

// Fungsi gabung nama dengan void
void gabung_nama_void(const char* depan, const char* belakang){
    //hitung dulu total panjang keduanya
    int totalLen = strlen(depan) + strlen(belakang) + 1; // +1 adalah untuk null terminator

    //alokasi memori untuk string return
    char* digabung = (char*)malloc(totalLen*sizeof(char));
    if (digabung == NULL){
        perror("Alokasi memori gagal");
        exit(1);
    }
    
    strcpy(digabung, depan);
    strcat(digabung, " ");
    strcat(digabung, belakang);
    
    printf("void_%s", digabung);
}


// SOAL 3 : Fungsi cek password
// Fungsi cek password dengan return value
bool cek_password(const char* passwd){
    if (strlen(passwd) > 8){
        if (strchr(passwd, '!') != NULL){
            return true;
        }
        return false;
    }
    return false;
}

// Fungsi cek password dengan void
void cek_password_void(const char* passwd){
    int temp = 0;
    if (strlen(passwd) > 8){
        if (strchr(passwd, '!') != NULL){
            printf("Void_Password baik");
            exit(0);
        }
        printf("Void_Pasword kurang baik");
        exit(0);
    }
    printf("Void_Password kurang baik");
}

int main(){
    //SOAL 1
    //implementasi fungsi perpangkatan dengan return value
    printf("%d", perpangkatan(2,8));
    //implementasi fungsi perpangkatan void
    perpangkatan_void(2,8);

    //SOAL 2
    //Inisialisasi nama depan dan belakang
    const char* dpn = "Ahmad";
    const char* blkng = "Muhammad";
    //implementasi fungsi gabung nama dengan return value
    printf("%s\n", gabung_nama(dpn, blkng));
    //implementasi fungsi gabung nama void
    gabung_nama_void(dpn, blkng);

    //SOAL 3
    //inisialisasi string(char pointer) dan memasukkan password
    //karena password yang akan dihandle harus berbentuk immutable (const char*)
    //maka harus melakukan workaround dengan menetapkan buffer dan melempar isi buffer ke const char* password
    char buffer[100]; // Mutable buffer to read input
    const char* passwd; // Const pointer to store the input

    printf("\nMasukkan passsword yang dicek: ");
    if (scanf("%99s", buffer) == 1) { // baca < 99 char untuk menghindari overflow
        passwd = buffer; // lempar nilai buffer ke passwd
    } else {
        printf("gagal membaca input.\n");
    };

    //Implementasi fungsi cek password dengan return value
    if (cek_password(passwd) == true){
        printf("Password baik!\n");
    } else {
        printf("Password kurang baik\n");
    };
    //implementasi fungsi cek password void
    cek_password_void(passwd);

    return 0;
}