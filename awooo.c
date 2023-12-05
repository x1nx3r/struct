#include <stdio.h>
#include <string.h>
#include <time.h>

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
    // Record start time
    clock_t start = clock();

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
    
    // Record the end time
    clock_t end = clock();

    // Calculate the CPU time used
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Waktu yang dihabiskan: %f seconds\n", cpu_time_used);
}

void selectionSort(struct Mahasiswa identitas[], int size, int (*compare)(const struct Mahasiswa *, const struct Mahasiswa *)) {
    // Record start time
    clock_t start = clock();

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

            printf("swapping %s with %s\n", identitas[i].nama, identitas[minIndex].nama);
        }
    }
    // Record the end time
    clock_t end = clock();

    // Calculate the CPU time used
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Waktu yang dihabiskan: %f seconds\n", cpu_time_used);
}

void insertionSort(struct Mahasiswa identitas[], int size, int (*compare)(const struct Mahasiswa *, const struct Mahasiswa *)) {
    // Record start time
    clock_t start = clock();

    for (int i = 1; i < size; i++) {
        struct Mahasiswa key = identitas[i];
        int j = i - 1;

        while (j >= 0 && compare(&identitas[j], &key) > 0) {
            identitas[j + 1] = identitas[j];
            j = j - 1;

            printf("Swapping %s with %s\n", identitas[j + 1].nama, key.nama);
        }
        identitas[j + 1] = key;
    }
    // Record the end time
    clock_t end = clock();

    // Calculate the CPU time used
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Waktu yang dihabiskan: %f seconds\n", cpu_time_used);
}

// fungsi interpolation search
int interpolationSearch(const struct Mahasiswa identitas[], int size, const char key[]) {
    // Record start time
    clock_t start = clock();
    
    int low = 0;
    int high = size - 1;

    while (low <= high && strcmp(key, identitas[low].nama) >= 0 && strcmp(key, identitas[high].nama) <= 0) {
        if (low == high) {
            if (strcmp(identitas[low].nama, key) == 0) return low;
            return -1;  // Element not found
        }

        // Interpolation formula
        int pos = low + ((high - low) / (strcmp(identitas[high].nama, identitas[low].nama))) * (strcmp(key, identitas[low].nama));
        
        if (strcmp(identitas[pos].nama, key) == 0) return pos;

        if (strcmp(identitas[pos].nama, key) < 0)
            low = pos + 1;
        else
            high = pos - 1;
    }

    // Record the end time
    clock_t end = clock();

    // Calculate the CPU time used
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Waktu yang dihabiskan: %f seconds\n", cpu_time_used);

    return -1;  // Element not found
}

// fungsi binary search
int binarySearch(const struct Mahasiswa identitas[], int size, const char key[]) {
    // Record start time
    clock_t start = clock();
    
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cmp = strcmp(identitas[mid].nama, key);

        if (cmp == 0) return mid;  // Element found
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }

    // Record the end time
    clock_t end = clock();

    // Calculate the CPU time used
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Time taken by interpolationSearch: %f seconds\n", cpu_time_used);

    return -1;  // Element not found
}

// fungsi display menu agar tidak memenuhi main
void display_main_menu() {
    printf("------Pengurutan dan Pencarian Data Mahasiswa------\n");
    printf("1. Urutkan dengan Bubble Sort\n");
    printf("2. Urutkan dengan Selection Sort\n");
    printf("3. Urutkan dengan Insertion Sort\n");
    printf("4. Cari berdasarkan nama dengan Binary Search\n");
    printf("5. Cari berdasarkan nama dengan Interpolation Search\n");
    printf("Fungsi search akan secara otomatis mengurutkan data berdasarkan nama\n");
}

// fungsi display char_menu agar tidak memenuhi main
void display_pilihan_sort() {
    printf("1. Sort Berdasarkan Nama\n");
    printf("2. Sort Berdasarkan NPM\n");
    printf("3. Sort Berdasarkan Prodi\n");
    printf("4. Sort Berdasarkan IPK\n");
}

void menu_search(){
    printf("");
}

int main() {
    // setting initial value untuk tiap char agar tidak terjadi undefined identifier
    struct Mahasiswa identitas[] = {
        {"Aisyah", "22081800513", "Akuntansi", 1.1},
        {"Andi", "22081134013", "Ekonomi Pembangunan", 3.6},
        {"Fitri", "23081013432", "Fisika", 1.9},
        {"Opang", "20081010133", "Teknik Industri", 3.3},
        {"Slamet", "19012010043", "Teknik Sipil", 3.4},
        {"Tono", "22081008122", "Sistem Informasi", 2.6},
        {"Udin", "17081010013", "Informatika", 2.7}
    };

    int jmlMahasiswa = sizeof(identitas) / sizeof(identitas[0]);

    // main loop untuk main menu
    while (1) {
        int choice = 0;
        display_main_menu();
        scanf("%d", &choice);

        //switch case untuk pilihan menu
        switch (choice) {
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
                continue;                               // use continue so the loop starts over
            }
            break;
        case 2:
            choice = 0;
            display_pilihan_sort();
            scanf("%d", &choice);
            switch (choice) {
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
                printf("Enter the correct value!\n"); // error statement
                continue;                             // use continue so the loop starts over
            }
            break;
        case 3:
            choice = 0;
            display_pilihan_sort();
            scanf("%d", &choice);
            switch (choice) {
            case 1: // Insertion sort berdasarkan nama
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by nama (insertion):\n");
                insertionSort(identitas, jmlMahasiswa, compareByNama);

                printf("\nSorted by nama (insertion):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 2: // Insertion sort berdasarkan npm
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by npm (insertion):\n");
                insertionSort(identitas, jmlMahasiswa, compareByNpm);

                printf("\nSorted by npm (insertion):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 3: // Insertion sort berdasarkan prodi
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by prodi (insertion):\n");
                insertionSort(identitas, jmlMahasiswa, compareByProdi);

                printf("\nSorted by prodi (insertion):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            case 4:
                printf("Urutan Sebelumnya :\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                printf("\nSorting by ipk (insertion):\n");
                insertionSort(identitas, jmlMahasiswa, compareByIpk);

                printf("\nSorted by ipk (insertion):\n");
                for (int i = 0; i < jmlMahasiswa; i++) {
                    printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", identitas[i].nama, identitas[i].npm, identitas[i].prodi, identitas[i].ipk);
                }
                break;
            default:
                printf("Enter the correct value!\n"); //error statement
                continue;                               // use continue so the loop starts over
            }
            break;

        case 4: //binary search
            printf("Masukkan nama yang akan di search: ");
            char searchKey[50];
            scanf("%s", searchKey);
            bubbleSort(identitas, jmlMahasiswa, compareByNama);
            int result = interpolationSearch(identitas, jmlMahasiswa, searchKey);
            if (result != -1) {
                printf("Ditemukan di index: %d\n", result);
                printf("Dengan identitas lengkap: Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n",
                    identitas[result].nama, identitas[result].npm, identitas[result].prodi, identitas[result].ipk);
            } else {
                printf("Tidak ditemukan.\n");
            }
            break;
        case 5:
            printf("Masukkan nama yang akan di search: ");
            char Key[50];
            scanf("%s", Key);
            bubbleSort(identitas, jmlMahasiswa, compareByNama);
            int resultInterpolation = binarySearch(identitas, jmlMahasiswa, Key);
            if (resultInterpolation != -1) {
                printf("Ditemukan di index: %d\n", resultInterpolation);
                printf("Dengan identitas lengkap: Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n",
                    identitas[resultInterpolation].nama, identitas[resultInterpolation].npm, identitas[resultInterpolation].prodi, identitas[resultInterpolation].ipk);
            } else {
                printf("Tidak ditemukan.\n");
            }
            break;
        default:
            printf("Enter the correct value!\n"); //error statement
            continue;                               // use continue so the loop starts over
        }
    }
    return 0;
}
