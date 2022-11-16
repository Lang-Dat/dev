/**
 *	author: Lang Dat
 *	create: 16-11-2022 45:51:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int LIS(int *nums, int n) {
    // longest incresing subsequence
    // TC: O(N logN)
    // SC: O(N)
    static const int INF = 1e9;
    vector<int> dp(n+1, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[j-1] < nums[i] && nums[i] < dp[j])
            dp[j] = nums[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] < INF)
            ans = i;
    }
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./LIS.INP", "r", stdin);
    freopen("./LIS.OUT", "w", stdout);
    #endif

    int n, best = 0;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    best = LIS(nums, n);
    std::cout << best << "";
    return 0;
}