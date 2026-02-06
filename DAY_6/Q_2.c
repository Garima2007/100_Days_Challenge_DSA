/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/
#include <stdio.h>
#include "move_zeroes.h"
void moveZeroes(int* nums, int numsSize) 
{
    int lastNonZero = 0;
    for (int i = 0; i < numsSize; i++) 
{
        if (nums[i] != 0) 
{
            if (i != lastNonZero) 
{
                int temp = nums[lastNonZero];
                nums[lastNonZero] = nums[i];
                nums[i] = temp;
            }
            lastNonZero++;
        }
    }
}
void printArray(int* nums, int numsSize) 
{
    printf("[");
    for (int i = 0; i < numsSize; i++) 
{
        printf("%d", nums[i]);
        if (i < numsSize - 1) printf(", ");
    }
    printf("]\n");
}
