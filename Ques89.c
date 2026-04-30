/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>

// Check function: kya allocation possible hai?
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m) {
                return 0; // not possible
            }
        }
    }
    return 1; // possible
}

// Main function
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int max = arr[0], sum = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1; // increase limit
        }
    }

    return result;
}

// Driver code
int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};

    int answer = allocateBooks(arr, n, m);

    printf("Minimum possible maximum pages = %d\n", answer);

    return 0;
}
