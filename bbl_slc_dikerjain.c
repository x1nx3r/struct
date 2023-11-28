#include <stdio.h>
#include <string.h>

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


int main() {
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

    printf("Original order:\n");
    for (int i = 0; i < jmlMahasiswa; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
    }

    // Sort by nama
    printf("\nSorting by nama:\n");
    bubbleSort(identitas, jmlMahasiswa, compareByNama);

    printf("\nSorted by nama:\n");
    for (int i = 0; i < jmlMahasiswa; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
    }

    // Sort by npm number
    printf("\nSorting by npm number:\n");
    bubbleSort(identitas, jmlMahasiswa, compareByNpm);

    printf("\nSorted by npm number:\n");
    for (int i = 0; i < jmlMahasiswa; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
    }

    // Sort by prodi
    printf("\nSorting by prodi number:\n");
    bubbleSort(identitas, jmlMahasiswa, compareByProdi);

    printf("\nSorted by prodi number:\n");
    for (int i = 0; i < jmlMahasiswa; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
    }

    // Sort by ipk (selection)
    printf("\nSorting by IPK (selection):\n");
    selectionSort(identitas, jmlMahasiswa, compareByIpk);

    printf("\nSorted by IPK:\n");
    for (int i = 0; i < jmlMahasiswa; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
    }

    return 0;
}