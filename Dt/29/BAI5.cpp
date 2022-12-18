/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 36:16:09
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int MOD = 1e9 + 7;
static const int LIM = 1e6 + 6;
static uint64_t nums[LIM], pre_sum[LIM], pre_sum2[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    int n;
    uint64_t ans = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        pre_sum[i] = pre_sum[i-1] + nums[i];
    }
        
    for (int i = n; i > 0; i--)
        pre_sum2[i] = pre_sum2[i+1] + nums[i] * (pre_sum[n] - pre_sum[i]);

    for (int i = 1; i <= n; i++)
        ans = (ans + nums[i] * pre_sum2[i+1]);

    std::cout << ans << "";
    return 0;
}