/*
1552. Magnetic Force Between Two Balls
Constraints:

n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length
*/
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int* position, int n, int m, int dist) {
    int count = 1;
    int last = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
        }
    }

    return count >= m;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}
