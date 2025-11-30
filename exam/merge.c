#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[50];

    // Merge two sorted halves
    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements
    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    // Copy back to original array
    k = 0;
    for (int x = l; x <= r; x++)
        arr[x] = temp[k++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return; // Only 1 element → already sorted

    int m = (l + r) / 2;

    mergeSort(arr, l, m);       // Sort left
    mergeSort(arr, m + 1, r);   // Sort right
    merge(arr, l, m, r);        // Merge
}

int main() {
    int arr[50], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
