347. Top K Frequent Elements
  Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Node;

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node* heap, int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;

    if(right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* unique = (int*)malloc(numsSize * sizeof(int));
    int* freq = (int*)calloc(numsSize, sizeof(int));
    int uniqueSize = 0;

    for(int i = 0; i < numsSize; i++) {
        int found = 0;
        for(int j = 0; j < uniqueSize; j++) {
            if(unique[j] == nums[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            unique[uniqueSize] = nums[i];
            freq[uniqueSize] = 1;
            uniqueSize++;
        }
    }

    Node* heap = (Node*)malloc(k * sizeof(Node));
    int heapSize = 0;

    for(int i = 0; i < uniqueSize; i++) {
        Node newNode = {unique[i], freq[i]};

        if(heapSize < k) {
            heap[heapSize++] = newNode;
            for(int j = heapSize/2 - 1; j >= 0; j--)
                heapify(heap, heapSize, j);
        } else if(newNode.freq > heap[0].freq) {
            heap[0] = newNode;
            heapify(heap, heapSize, 0);
        }
    }

    int* ans = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) {
        ans[i] = heap[i].num;
    }

    *returnSize = k;
    return ans;
}
