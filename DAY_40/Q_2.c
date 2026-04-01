739. Daily Temperatures
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
void dailyTemperatures(int temp[], int n, int result[])
{
    int stack[1000];
    int top = -1;

    for(int i = 0; i < n; i++)
    {
        while(top != -1 && temp[i] > temp[stack[top]])
        {
            int index = stack[top--];
            result[index] = i - index;
        }
        stack[++top] = i;
    }
}

int main()
{
    int temp[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temp)/sizeof(temp[0]);
    int result[n];

    for(int i = 0; i < n; i++)
        result[i] = 0;

    dailyTemperatures(temp, n, result);

    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}
