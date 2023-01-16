/**
 *	author : Lăng Trọng Đạt
 *	creater: 15-01-2023 08:28:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];
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
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./Treelamp.INP", "r", stdin);
    freopen("./Treelamp.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::cout << lengthOfLIS(nums, n) << "";
    return 0;
}