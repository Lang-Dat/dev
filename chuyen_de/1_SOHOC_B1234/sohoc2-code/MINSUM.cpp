/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 49:18:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MINSUM.INP", "r", stdin);
    freopen("./MINSUM.OUT", "w", stdout);
    #endif

    uint64_t gcd, lcm, product, best = INT32_MAX;
    std::cin >> gcd >> lcm;
    if (lcm % gcd != 0) {
        std::cout << -1 << "";
        return 0;
    }
    for (int i = 1; i * i <= lcm / gcd; i++) {
        if ((lcm / gcd) % i == 0) {
            int j = lcm / gcd / i;
            if (__gcd(i, j) == 1) {
                best = min(best, gcd*(i+j));
            }
        }
    }

    std::cout << (best != INT32_MAX ? best : -1) << "";
    return 0;
}