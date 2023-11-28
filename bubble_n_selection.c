/*

    TUGAS PEMROGRAMAN LANJUT (Bubble Sort dan Selection Sort)
    NAMA : Muhammad Mega Nugraha
    NPM : 22081010213
    KELAS : E081

*/

#include <stdio.h>
#include <string.h>

// Struct template untuk character profile
struct Mahasiswa {
    char nama[50];
    char npm[15];
    char prodi[24];
    float ipk;
};

int compareByNama(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->nama, b->nama);
}

int compareByNpm(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->npm, b->npm);
}

int compareByProdi(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->prodi, b->prodi);
}

int compareByIpk(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    if (a->ipk < b->ipk) {
        return -1;
    } else if (a->ipk > b->ipk) {
        return 1;
    } else {
        return 0;
    }
}

void bubbleSort(struct Mahasiswa identitas[], int size, int (*compare)(const struct Mahasiswa *, const struct Mahasiswa *)) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(&identitas[j], &identitas[j + 1]) > 0) {
                struct Mahasiswa temp = identitas[j];
                identitas[j] = identitas[j + 1];
                identitas[j + 1] = temp;
                swapped = 1;

                printf("Swapping %s with %s\n", identitas[j].nama, identitas[j + 1].nama);
            }
        }
        if (swapped == 0) {
            // If no two elements were swapped in the inner loop, the array is already sorted.
            break;
        }
    }
}

void selectionSort(struct Mahasiswa identitas[], int size, int (*compare)(const struct Mahasiswa *, const struct Mahasiswa *)) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(&identitas[j], &identitas[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap the elements if necessary
            struct Mahasiswa temp = identitas[i];
            identitas[i] = identitas[minIndex];
            identitas[minIndex] = temp;
            
            printf("Swapping %s with %s\n", identitas[i].nama, identitas[minIndex].nama);
        }
    }
}

// fungsi display menu agar tidak memenuhi main
void display_main_menu(){
    printf("------Pengurutan Data Mahasiswa------\n");
    printf("1. Urutkan dengan Bubble Sort\n");
    printf("2. Urutkan dengan Selection Sort\n");
}

// fungsi display char_menu agar tidak memenuhi main
void display_pilihan_sort(){
    printf("1. Sort Berdasarkan Nama\n");
    printf("2. Sort Berdasarkan NPM\n");
    printf("3. Sort Berdasarkan Prodi\n");
    printf("3. Sort Berdasarkan IPK\n");    
}

int main() {
    // setting initial value untuk tiap char agar tidak terjadi undefined identifier
    struct Mahasiswa identitas[] = {
        {"Udin", "17081010013", "Informatika", 2.7},
        {"Slamet", "19012010043", "Teknik Sipil", 3.4},
        {"Opang", "20081010133", "Teknik Industri", 3.3},
        {"Aisyah", "22081800513", "Akuntansi", 1.1},
        {"Andi", "22081134013", "Ekonomi Pembangunan", 3.6},
        {"Tono", "22081008122", "Sistem Informasi", 2.6},
        {"Fitri", "23081013432", "Fisika", 1.9},
    };

    int jmlMahasiswa = sizeof(identitas) / sizeof(identitas[0]);

    // main loop untuk main menu
    while(1){
        int choice=0;
        display_main_menu();
        scanf("%d", &choice);

        //switch case untuk pilihan menu
        switch (choice)
        {
        case 1:
            choice = 0;
            display_pilihan_sort();
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // Bubble sort berdasarkan nama 
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by nama (bubble):\n");
                bubbleSort(identitas, jmlMahasiswa, compareByNama);

                printf("\nSorted by nama (bubble):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 2: // Bubble sort berdasarkan npm
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by npm (bubble):\n");
                bubbleSort(identitas, jmlMahasiswa, compareByNpm);

                printf("\nSorted by npm (bubble):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 3: // Bubble sort berdasarkan prodi
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by prodi (bubble):\n");
                bubbleSort(identitas, jmlMahasiswa, compareByProdi);

                printf("\nSorted by prodi (bubble):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 4:
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by ipk (bubble):\n");
                bubbleSort(identitas, jmlMahasiswa, compareByIpk);

                printf("\nSorted by ipk (bubble):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            default:
                printf("Enter the correct value!\n"); //error statement
                continue;   // use continue so the loop starts over
            }
            break;
        case 2:
            choice = 0;
            int brick;
            display_pilihan_sort();
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // Selection sort berdasarkan nama 
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by nama (selection):\n");
                selectionSort(identitas, jmlMahasiswa, compareByNama);

                printf("\nSorted by nama (selection):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 2: // Selection sort berdasarkan npm
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by npm (selection):\n");
                selectionSort(identitas, jmlMahasiswa, compareByNpm);

                printf("\nSorted by npm (selection):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 3: // Selection sort berdasarkan prodi
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by prodi (selection):\n");
                selectionSort(identitas, jmlMahasiswa, compareByProdi);

                printf("\nSorted by prodi (selection):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 4: // Selection sort berdasarkan ipk
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by ipk (selection):\n");
                selectionSort(identitas, jmlMahasiswa, compareByIpk);

                printf("\nSorted by ipk (selection):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            default:
                printf("Enter the correct value!\n"); //error statement
                continue;   // use continue so the loop starts over
            }
            break;
        default:
            printf("Enter the correct value!\n"); //error statement
            continue;   // use continue so the loop starts over
        }
    }
    return 0;
}
