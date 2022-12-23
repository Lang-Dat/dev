/**
 *	author: Lang Dat
 *	create: 16-11-2022 45:51:19
**/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int LNDS(int *nums, int *dp, int n) {
    // longest non-decresing subsequence
    int best = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] >= nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        best = max(best, dp[i]);
    }
    return best;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./LIQ.INP", "r", stdin);
    freopen("./LIQ.OUT", "w", stdout);
    #endif

    int n, best = 0;
    std::cin >> n;
    int nums[n], dp[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    memset(dp, 0, sizeof dp);
    best = LNDS(nums, dp, n);
    std::cout << best << "";
    return 0;
}