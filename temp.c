#include <stdio.h>
#include <string.h>

// ... (existing code)

int interpolationSearch(const struct Mahasiswa identitas[], int size, const char key[]) {
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

    return -1;  // Element not found
}

int binarySearch(const struct Mahasiswa identitas[], int size, const char key[]) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cmp = strcmp(identitas[mid].nama, key);

        if (cmp == 0) return mid;  // Element found
        else if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }

    return -1;  // Element not found
}

// ... (existing code)

int main() {
    // ... (existing code)

    printf("Enter the name to search: ");
    char searchKey[50];
    scanf("%s", searchKey);

    // Use interpolation search or binary search after sorting
    // Example: Using interpolation search
    bubbleSort(identitas, jmlMahasiswa, compareByNama);
    int result = interpolationSearch(identitas, jmlMahasiswa, searchKey);

    // Example: Using binary search
    // bubbleSort(identitas, jmlMahasiswa, compareByNama);
    // int result = binarySearch(identitas, jmlMahasiswa, searchKey);

    if (result != -1) {
        printf("Found at index: %d\n", result);
        printf("Details: Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n",
               identitas[result].nama, identitas[result].npm, identitas[result].prodi, identitas[result].ipk);
    } else {
        printf("Not found.\n");
    }

    // ... (existing code)

    return 0;
}