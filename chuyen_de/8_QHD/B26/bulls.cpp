/**
 *	author : Lăng Trọng Đạt
 *	creater: 11-01-2023 19:50:28
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int MOD = 2111992;
static const int LIM = 1e6 + 5;
static int dp[LIM]; // dp[i]: số cách xếp i con bò đực
int n, k;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./bulls.INP", "r", stdin);
    freopen("./bulls.OUT", "w", stdout);
    #endif

    std::cin >> n >> k;

    for (int i = 0; i <= k; i++)
        dp[i] = i + 1;
    
    for (int i = k + 1; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i - k - 1]) % MOD;
    }

    std::cout << dp[n] << "";
    return 0;
}