20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
  
#include <stdbool.h>
#include <string.h>
bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } 
        else {
            if(top == -1) return false;

            char ch = stack[top--];

            if((s[i] == ')' && ch != '(') ||
               (s[i] == '}' && ch != '{') ||
               (s[i] == ']' && ch != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}
