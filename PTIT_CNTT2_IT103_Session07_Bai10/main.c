#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int X;

int compare(const void *a, const void *b) {
    int val1 = *(const int *)a;
    int val2 = *(const int *)b;

    int dist1 = abs(val1 - X);
    int dist2 = abs(val2 - X);

    if (dist1 < dist2) {
        return -1;
    } else if (dist1 > dist2) {
        return 1;
    } else {
        if (val1 < val2) {
            return -1;
        } else if (val1 > val2) {
            return 1;
        } else {
            return 0;
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {10, 5, 3, 9, 2, 8, 1, 7};
    int n = sizeof(a) / sizeof(a[0]);
    X = 6;

    printf("Mang ban dau: ");
    printArray(a, n);
    printf("Gia tri X = %d\n", X);

    qsort(a, n, sizeof(int), compare);

    printf("Mang sau khi sap xep: ");
    printArray(a, n);

    return 0;
}