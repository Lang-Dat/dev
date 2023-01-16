/**
 *	author: Lăng Trọng Đạt
 *	create: 07-12-2022 52:59:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLIS(int *nums, int n) {
    static const int INF = INT32_MAX;
    vector<int> dp(n+2, INF); // dp[i]: phần tử nhỏ nhất mà tại đó một dãy con độ dài i kết thúc
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (dp[j-1] < nums[i] && nums[i] < dp[j])
            dp[j] = nums[i];
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i+1] == INF) return i;
    }
}

int main()
{
    freopen("./LIS.INP", "r", stdin);
    freopen("./LIS.OUT", "w", stdout);
    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::cout << lengthOfLIS(nums, n) << "";
    return 0;
}