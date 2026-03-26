227. Basic Calculator II

#include <ctype.h>
#include <stdlib.h>

int calculate(char* s) {
    int n = 0;
    while (s[n] != '\0') n++;   // find length

    int* stack = (int*)malloc(sizeof(int) * n);
    int top = -1;

    int num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] *= num;
            }
            else if (op == '/') {
                stack[top] /= num;
            }

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    free(stack);  // important
    return result;
}
