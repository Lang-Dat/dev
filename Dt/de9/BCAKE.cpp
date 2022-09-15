#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BCAKE.INP", "r", stdin);
    freopen("./BCAKE.OUT", "w", stdout);

    int n;
    double r, h;
    std::cin >> n;
    double theTich[n];
    for (int i = 0; i < n; i++) {
        std::cin >> r >> h;
        theTich[i] = r*r*h*M_PI;
    }

    double dp[n]; // The tich lon nhat neu chon cai do
    // dp[n - 1] = theTich[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = theTich[i];
        double currMax = 0;
        for (int j = i + 1; j < n; j++) {
            if (theTich[j] > theTich[i] && dp[j] > currMax)
                currMax = dp[j];
        }
        dp[i] += currMax;
    }
    printf("%.3f", dp[0]);
    return 0;
}