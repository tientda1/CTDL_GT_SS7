#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
    int arr[1000];
    int n;
    do {
        printf("Nhap vao so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    printf("Nhap vao cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("Phan tu a[%d]: %d\n", i, arr[i]);
    }
    return 0;
}