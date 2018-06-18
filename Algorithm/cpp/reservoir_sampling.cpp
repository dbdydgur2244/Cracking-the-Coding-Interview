#include <cstdio>
#include <time.h>

/**
 * Implementation reservoir sampling.
 * This function use in array, but it can be implement without array!
 * When the i-th item arrives(for i > 10)
 *    - with probability 10 / i, keep the new item
 *    - with probability 1 - 10 / i, keep the old items.
 * so i < 10, keep probability 1
 *    i> 11, keep probability 1 - 10 / i
 * Time complexity: O(n)
 * space complexity: O(k)
 */
void reservoir_sampling(int in[], int n, int k)
{
    int reservoir[k];
    srand(time(NULL));
    for (int i = 0; i < k; ++i)
        reservoir[i] = in[i];
    for (int i = 0; i < n; ++i) {
        int j = rand() % (i + 1);
        if (j < k)
            reservoir[j] = in[i];
    }
}
