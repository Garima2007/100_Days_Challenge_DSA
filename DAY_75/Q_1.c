/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;
    int hash[20001];

    for (int i = 0; i < 20001; i++)
        hash[i] = -2;

    hash[10000] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (hash[sum + 10000] != -2) {
            int len = i - hash[sum + 10000];
            if (len > max_len)
                max_len = len;
        } else {
            hash[sum + 10000] = i;
        }
    }

    return max_len;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}
