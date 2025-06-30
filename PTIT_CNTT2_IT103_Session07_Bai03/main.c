#include <stdio.h>

void insertionSort(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
    }
}

int main(void) {
    int arr[1000];
    int n = 0;
    do {
        printf("Nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
    }while (n < 1 || n > 1000);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu: ");
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}