/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int sum;
    int freq;
} Node;

int findIndex(Node* hash, int size, int sum) {
    for (int i = 0; i < size; i++) {
        if (hash[i].sum == sum) return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    Node* hash = (Node*)malloc(n * sizeof(Node));
    int hashSize = 0;
    
    int currentSum = 0;
    int count = 0;
    
    hash[hashSize].sum = 0;
    hash[hashSize].freq = 1;
    hashSize++;
    
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        
        int idx = findIndex(hash, hashSize, currentSum);
        if (idx != -1) {
            count += hash[idx].freq;
            hash[idx].freq += 1;
        } else {
            hash[hashSize].sum = currentSum;
            hash[hashSize].freq = 1;
            hashSize++;
        }
    }
    
    printf("%d\n", count);
    
    free(arr);
    free(hash);
    return 0;
}
