/**
 *	author: Lăng Trọng Đạt
 *	create: 11-12-2022 05:10:18
**/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long double calc(int n) {
    if (n >= 1e6) {
        return log2(n) - 2*0.5772156649;
    } else {
        double ans = 0;
        // std::cin >> n;
        for (int i = 1; i <= n; i++) {
            ans += (long double) 1 / i;
            // std::cout << i << " " << ans << " " << ans - log2(i) + 2*0.5772156649 << "\n";
        }
        return ans;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./capso.INP", "r", stdin);
    freopen("./capso.OUT", "w", stdout);
    #endif

    int n, count = 0;
    std::cin >> n;

    std::cout << (int64_t)((long double) n*calc(n)) << "";
    return 0;
}