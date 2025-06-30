#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int soSanhTangDan(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int soSanhGiamDan(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void sapXepChanLe(int arr[], int n) {
    int mang_chan[MAX_SIZE];
    int mang_le[MAX_SIZE];
    int so_luong_chan = 0;
    int so_luong_le = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            mang_chan[so_luong_chan] = arr[i];
            so_luong_chan++;
        } else {
            mang_le[so_luong_le] = arr[i];
            so_luong_le++;
        }
    }

    qsort(mang_chan, so_luong_chan, sizeof(int), soSanhTangDan);

    qsort(mang_le, so_luong_le, sizeof(int), soSanhGiamDan);

    int chi_so = 0;

    for (int i = 0; i < so_luong_chan; i++) {
        arr[chi_so] = mang_chan[i];
        chi_so++;
    }

    for (int i = 0; i < so_luong_le; i++) {
        arr[chi_so] = mang_le[i];
        chi_so++;
    }
}

void inMang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n;

    do {
        printf("Nhap vao so luong phan tu (0 < n < %d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n <= 0 || n >= MAX_SIZE) {
            printf("So luong khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n >= MAX_SIZE);

    printf("Nhap vao cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nMang truoc khi sap xep: ");
    inMang(arr, n);

    sapXepChanLe(arr, n);

    printf("Mang sau khi sap xep (Chan tang dan - Le giam dan): ");
    inMang(arr, n);

    return 0;
}