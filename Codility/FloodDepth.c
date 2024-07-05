// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {


    if (N < 3) {
        return 0;  // Less than 3 blocks cannot form any basin.
    }

    // Create arrays to store the maximum heights to the left and right of each block
    int *leftMax = (int *)malloc(N * sizeof(int));
    int *rightMax = (int *)malloc(N * sizeof(int));

    // Fill the leftMax array
    leftMax[0] = A[0];
    for (int i = 1; i < N; i++) {
        leftMax[i] = (A[i] > leftMax[i - 1]) ? A[i] : leftMax[i - 1];
    }

    // Fill the rightMax array
    rightMax[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rightMax[i] = (A[i] > rightMax[i + 1]) ? A[i] : rightMax[i + 1];
    }

    // Calculate the maximum water depth
    int maxDepth = 0;
    for (int i = 1; i < N - 1; i++) {
        int waterLevel = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        int depth = waterLevel - A[i];
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    // Free the allocated memory
    free(leftMax);
    free(rightMax);

    return maxDepth;
}