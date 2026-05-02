/*
164. Maximum Gap
Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    if (min == max) return 0;

    int gap = (max - min + numsSize - 2) / (numsSize - 1);
    int bucketCount = (max - min) / gap + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - min) / gap;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0, prev = min;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;

        int currGap = bucketMin[i] - prev;
        if (currGap > maxGap) maxGap = currGap;

        prev = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}
