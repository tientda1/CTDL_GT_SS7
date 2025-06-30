#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
    }
}

int main(void) {
    int arr[1000];
    int n = 0;
    do {
        printf("Nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
    }while (n < 1);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu: ");
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}