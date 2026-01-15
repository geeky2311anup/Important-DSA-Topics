#include <stdio.h>

int main() {
    int i, j, k;

    // Read two integers i and j
    scanf("%d%d", &i, &j);

    // Compute the difference
    k = i - j;

    // If the last digit of k is not 9, increment k by 1
    // Otherwise, decrement k by 1
    // This ensures the result differs slightly from the exact difference
    if (k % 10 != 9)
        k++;
    else
        k--;

    // Print the final modified value
    printf("%d\n", k);

    return 0;
}
