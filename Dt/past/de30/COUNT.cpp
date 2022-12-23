#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

const int MOD = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./COUNT.INP", "r", stdin);
    freopen("./COUNT.OUT", "w", stdout);

    long long n, ans = 1;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++)
        ans = (ans % MOD * 2) % MOD;
    std::cout << ans;

    return 0;
}