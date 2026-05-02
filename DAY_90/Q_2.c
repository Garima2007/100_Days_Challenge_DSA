/*
410. Split Array Largest Sum
Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/
int canSplit(int* nums, int n, int k, int maxSum) {
    int parts = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + nums[i] <= maxSum) {
            sum += nums[i];
        } else {
            parts++;
            sum = nums[i];
        }
    }

    return parts <= k;
}

int splitArray(int* nums, int numsSize, int k) {
    int maxVal = 0, total = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
        total += nums[i];
    }

    int low = maxVal, high = total, ans = total;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
