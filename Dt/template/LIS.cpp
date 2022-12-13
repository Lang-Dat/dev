#include <bits/stdc++.h>

int lengthOfLIS(int *nums, int n) {
    static const int INF = INT32_MAX;
    std::vector<int> dp(n+2, INF); // dp[i]: phần tử nhỏ nhất mà tại đó một dãy con độ dài i kết thúc
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = std::upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[j-1] < nums[i] && nums[i] < dp[j])
            dp[j] = nums[i];
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i+1] == INF) return i;
    }
}