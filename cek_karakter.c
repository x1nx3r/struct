/*

    TUGAS 1 PEMROGRAMAN LANJUT (STRUCT)
    NAMA : Muhammad Mega Nugraha
    NPM : 22081010213
    KELAS : E081

*/

#include<stdio.h>   
#include<string.h>  //Module untuk fungsi manipulasi string
#include<stdbool.h>

//fungsi untuk menghitung jumlah karakter tanpa spasi
int hitung_karakter(const char* string){
    int space;
    int len=strlen(string);
    for (const char *ptr = string; *ptr != '\0'; ++ptr) {
        if (*ptr == ' '){
            ++space;
            continue;
        }
    }
    return len-space;
}

//fungsi untuk menghitung jumlah kata
int hitung_kata(const char* string){
    int word = 0;
    bool status;
    for (const char *ptr = string; *ptr != '\0'; ++ptr) {
        if (*ptr == ' '){
            if (status==true){
                ++word;
                status=false;
            }
        } else {
            status=true;
        }
    }
    if (status==true){
        ++word;
    }
    return word;
}

//fungsi untuk menghitung jumlah kata yang sama
int hitung_kata_sama (const char* string, const char* kata){
    int count = 0;
    size_t panjang_kata = strlen(kata);

    // mulai iterasi dengan kondisi strstr(ptr, kata)
    for (const char* ptr = string; (ptr = strstr(ptr, kata)) != NULL; ++ptr) {
        //+1 setiap ada kata yang ditemukan/strstr(ptr, kata) != NULL
        ++count;
        //Majukan pointer ptr sebanyak panjang kata - 1 agar tidak menghitung ulang kata yang sudah dihitung
        ptr += panjang_kata - 1;
    }

    return count;
}

int main(){
    const char* soal = "Dennis MacAlistair Ritchie (9 September 1941 - 12 Oktober 2011) adalah seorang ilmuwan komputer yang dikenal atas sumbangsihnya membuat bahasa pemrograman C dan berbagai sistem operasi seperti Multics dan Unix. Ritchie menerima penghargaan Turing Award pada tahun 1983 dan National Medal of Technology 1998 pada 21 April 1999. Ia menjabat sebagai kepala Departemen Riset Perangkat lunak Sistem di Lucent Technologies saat pensiun pada tahun 2007. Ritchie dikenal sebagai pembuat bahasa pemrograman C, pengembang utama sistem operasi, dan sebagai salah satu dari penulis (bersama Brian Kernighan) buku Kamus Bahasa C, The C Programming Language. Penemuan bahasa C dan pengembangan Unix menjadikan Ricthie dan Ken Thompson sebagai pionir utama dunia komputasi modern. Bahasa C hingga kini masih digunakan secara luas dalam program aplikasi, sistem operasi, pengembangan sistem benam, dan pengaruhnya dalam bahasa pemrograman modern lain. Sedangkan Unix juga telah memberikan pengaruh besar, membangun konsep dan prinsip dalam dunia komputasi masa kini";
    const char* soala = "satusatu satu lima";

    //Implementasi menghitung karakter
    printf("banyak karakter tanpa spasi : %d\n", hitung_karakter(soal));
    printf("banyak karakter dengan spasi : %d\n", strlen(soal));

    //Implementasi menghitung kata
    printf("banyak kata : %d\n", hitung_kata(soal));

    //Implementasi mencari satu kata dalam string menggunakan strstr()
    const char* str = "dan";
    const char* result = strstr(soal, str);
    if (result != NULL){
        printf("kata '%s' ditemukan\n", str);
    };

    //Implementasi mencari jumlah kata yang identik dalam string
    printf("banyak jumlah kata '%s' adalah : %d\n", str, hitung_kata_sama(soal, str));

    return 0;
}


