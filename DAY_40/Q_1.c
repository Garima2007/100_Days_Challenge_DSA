*/Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
  #include <stdio.h>
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for(int i = n-1; i >= 0; i--)
    {
        // Swap root with last element
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[] = {4, 10, 3, 5, 1};
    int n = sizeof(a)/sizeof(a[0]);

    heapSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}
