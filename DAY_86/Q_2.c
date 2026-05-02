/*
69. Sqrt(x)
Constraints:
0 <= x <= 231 - 1
*/
int mySqrt(int x) {
    if (x <= 1) return x;

    int low = 1, high = x, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
