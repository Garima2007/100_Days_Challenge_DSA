/*
239. Sliding Window Maximum
*/
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));
    
    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        if (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            result[idx++] = nums[deque[front]];
    }

    *returnSize = idx;
    return result;
}
