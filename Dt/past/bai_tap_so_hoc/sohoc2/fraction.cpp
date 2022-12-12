/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 05:26:19
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./fraction.INP", "r", stdin);
    freopen("./fraction.OUT", "w", stdout);
    #endif

    uint64_t n, b, ans = 0;
    std::cin >> b >> n;
    uint64_t sq = n * n;

    for (int64_t i = 0; i <= 2 * n; i++) {
        if ((b * i * (2*n - i)) % sq == 0)
            ans += (i != n);
    }

    std::cout << ans - 1 << "";

    return 0;
}