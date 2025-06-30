#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void customSort(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] < 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 0) {
            mid++;
        } else {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
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

    customSort(arr, n);

    printf("Mang sau khi duoc sap xep (Am - 0 - Duong): ");
    printArray(arr, n);

    return 0;
}