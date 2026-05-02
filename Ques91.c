#include <stdio.h>

// Function to check if boards can be painted within max_time using k painters
int canPaint(int boards[], int n, int k, int max_time) {
    int painters = 1;
    int curr_time = 0;

    for (int i = 0; i < n; i++) {
        if (curr_time + boards[i] <= max_time) {
            curr_time += boards[i];
        } else {
            painters++;
            curr_time = boards[i];

            if (painters > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try smaller
        } else {
            low = mid + 1;  // Increase limit
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];
    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int ans = minTime(boards, n, k);
    printf("Minimum time required = %d\n", ans);

    return 0;
}
