long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long sum = 0;
    for (int i = 0; i < batteriesSize; i++) {
        sum += batteries[i];
    }

    long long left = 0;
    long long right = sum / n;
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long available = 0;

        for (int i = 0; i < batteriesSize; i++) {
            available += (batteries[i] < mid) ? batteries[i] : mid;
        }

        if (available >= mid * n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}