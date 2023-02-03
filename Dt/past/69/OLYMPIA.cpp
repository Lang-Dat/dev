/**
 *	author : Lăng Trọng Đạt
 *	creater: 30-01-2023 14:07:02
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int MOD = 1e9 + 7;
static const int LIM = 1e6 + 5;
static int nums[LIM];
int n, k, p;
uint64_t ans = 0, total = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./OLYMPIA.INP", "r", stdin);
    freopen("./OLYMPIA.OUT", "w", stdout);
    #endif

    std::cin >> n >> k >> p;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        total += nums[i];
    }
    
    total %= MOD;

    ans = total * (k / n) % MOD;
    k %= n;

    for (int i = (p - 1) % n; k > 0; i++, k--) {
        ans = (ans + nums[i % n]) % MOD;
    }

    std::cout << ans << "";

    return 0;
}