/**
 *	author : Lăng Trọng Đạt
 *	creater: 07-01-2023 48:58:20
**/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

static const int LIM = 1e6 + 5;
static pair<int, int> nums[LIM];
static int dp[LIM];

bool check(pair<int, int> &smaller, pair<int, int>& bigger) {
    return (smaller.second < bigger.second and 
        smaller.first < bigger.first);
}

int lengthOfLIS(int n) {
    static const int INF = INT32_MAX;
    std::vector<pair<int, int>> dp(n+2, {INF, INF}); // dp[i]: phần tử nhỏ nhất mà tại đó một dãy con độ dài i kết thúc
    dp[0].first = -INF;
    for (int i = 0; i < n; i++) {
        int j = std::upper_bound(dp.begin(), dp.end(), bool) - dp.begin();
        if (check(dp[j-1], nums[i]) and check(nums[i], dp[j]))
            dp[j] = nums[i];
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i+1].first == INF) return i;
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./chonsach.INP", "r", stdin);
    freopen("./chonsach.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i].first >> nums[i].second;
    }
    
    sort(nums, nums + n);
    // int best = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (nums[j].second < nums[i].second and 
    //             nums[j].first < nums[i].first)
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //     }
    //     best = max(best, dp[i]);
    // }

    std::cout << lengthOfLIS(n) << "";

    return 0;
}