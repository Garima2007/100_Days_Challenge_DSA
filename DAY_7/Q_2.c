each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
#include <stdio.h>
int fib(int n) 
{
    if (n <= 1) return n;
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) 
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() 
{
    int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(test) / sizeof(test[0]);
    
    printf("Fibonacci numbers:\n");
    for (int i = 0; i < size; i++)
      {
        printf("fib(%d) = %d\n", test[i], fib(test[i]));
    }
    printf("\nEnter n (0-30): ");
    int n;
    scanf("%d", &n);
    if (n >= 0 && n <= 30) 
    {
        printf("fib(%d) = %d\n", n, fib(n));
    } else {
        printf("Invalid input. Must be between 0 and 30.\n");
    }
    
    return 0;
}
