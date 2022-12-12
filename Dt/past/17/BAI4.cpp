/**
 *	author: Lăng Trọng Đạt
 *	create: 07-12-2022 15:15:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
int64_t h[LIM], dp[LIM]; // dp[i]: số cây chọn được tối đa khi xuất phát từ i
int n;

int64_t solve(int pos = 0, int64_t curr = 0) {
    if (pos >= n - 3) {
        for (int i = pos; i < n; i++) curr += h[i];
        return curr;
    }
    if (dp[pos] != 0) return curr + dp[pos];
    dp[pos] = max(
                solve(pos + 6, h[pos] + h[pos+1] + h[pos+2]), max(
                solve(pos + 4, h[pos] + h[pos+1]),
                solve(pos + 2, h[pos])
    ));
    return dp[pos] + curr;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    
    std::cout << solve() << "\n";
    // for (int i = 0; i < n; i++) {
    //     std::cout << dp[i] << " ";
    // }

    return 0;
}