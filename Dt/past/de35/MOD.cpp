#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

ull n, MOD;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MOD.INP", "r", stdin);
    freopen("./MOD.OUT", "w", stdout);

    std::cin >> n >> MOD;
    std::cout << (n * (n+1) * (2*n + 1) / 6) % MOD << " ";

    return 0;
}