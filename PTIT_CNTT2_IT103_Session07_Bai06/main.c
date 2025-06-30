#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main() {
    int arr[1000];
    int n;

    do {
        printf("Nhap vao so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000) {
            printf("So luong khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n >= 1000);

    printf("Nhap vao cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep (Merge Sort): ");
    printArray(arr, n);

    return 0;
}