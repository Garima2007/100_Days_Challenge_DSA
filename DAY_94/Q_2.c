/*
1122. Relative Sort Array
Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001] = {0};

    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int* result = (int*)malloc(sizeof(int) * arr1Size);
    int index = 0;

    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    int* temp = (int*)malloc(sizeof(int) * arr1Size);
    int t = 0;

    for (int i = 0; i < arr1Size; i++) {
        if (count[arr1[i]] > 0) {
            temp[t++] = arr1[i];
            count[arr1[i]]--;
        }
    }

    qsort(temp, t, sizeof(int), compare);

    for (int i = 0; i < t; i++) {
        result[index++] = temp[i];
    }

    free(temp);
    *returnSize = arr1Size;
    return result;
}
