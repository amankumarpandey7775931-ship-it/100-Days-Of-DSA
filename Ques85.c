/*Problem: Implement Merge Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/
#include <stdio.h>

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];  // temporary arrays

    // Copy data to temp arrays
    for(i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for(j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Merge the temp arrays
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i = i + 1;
        } else {
            arr[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    // Copy remaining elements of L[]
    while(i < n1) {
        arr[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    // Copy remaining elements of R[]
    while(j < n2) {
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        // Sort first half
        mergeSort(arr, left, mid);

        // Sort second half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
