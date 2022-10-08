#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long
const int MOD = 2021;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SQROOT.INP", "r", stdin);
    freopen("./SQROOT.OUT", "w", stdout);

    ull n;
    std::cin >> n;
    n %= MOD;
    std::cout << (n * (n + 1) * (2*n + 1) / 6) % MOD;
    return 0;
}