Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;  
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}
int main() 
{
    int nums1[] = {3, 2, 2, 3};
    int val1 = 3;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    
    int k1 = removeElement(nums1, size1, val1);
    printf("Test 1 - k = %d\n", k1);
    printf("First %d elements: ", k1);
    for (int i = 0; i < k1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n\n");
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = removeElement(nums2, size2, val2);
    printf("Test 2 - k = %d\n", k2);
    printf("First %d elements: ", k2);
    for (int i = 0; i < k2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");
    
    return 0;
}
