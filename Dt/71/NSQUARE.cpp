/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 21:42:41
**/
#include <iostream>
#include <algorithm>
using namespace std;

// x^2 - y = a^2
// => (x - a)(x + a) = y;
// let p = x + a, q = x - a;
// so y = pq
// also p + q = 2x and x <= n
// => p <= 2n - q

static const int MOD = 1e9 + 7;
int64_t n, ans = 0;

int so_cap_uoc(int64_t n) {
    int res = 0;
    for (int i = 1; i * i <= n; i++)
        res += (n % i == 0 and (n / i - i) % 2 == 0);

    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./NSQUARE.INP", "r", stdin);
    freopen("./NSQUARE.OUT", "w", stdout);
    #endif

    std::cin >> n;

    for (int64_t q = 1; q * q <= n; q++) {
        int maxP = min(2*n - q, n / q);
        if (maxP < q) continue;
        int count = maxP - q + 1;
        ans += count / 2 + (int)(count & 1);
    }
        // ans += so_cap_uoc(i);

    std::cout << ans % MOD << "";
    return 0;
}