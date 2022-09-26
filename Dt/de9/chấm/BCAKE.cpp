#pragma GCC optimize("O2")
#include <stdio.h>
#include <iostream>
#include <map>

#define M_PI 3.14159265358979323846

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
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
    std::map<long double, int, std::greater<>> dp;
    for (int i = n - 1; i >= 0; i--) {
        long double currMax = 0;
        for (auto &itr : dp)
            if (theTich[itr.second] > theTich[i] && itr.first > currMax)
                currMax = itr.first;
        if (dp.count(currMax + theTich[i]) && theTich[dp[currMax + theTich[i]]] < theTich[i]) dp[currMax + theTich[i]] = i;
        else dp[currMax + theTich[i]] = i;
    }
    double ans = dp.begin()->first;
    printf("%.3f", ans);
    return 0;
}