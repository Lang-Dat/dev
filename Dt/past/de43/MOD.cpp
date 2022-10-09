#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long
const int MOD = 2017;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MOD.INP", "r", stdin);
    freopen("./MOD.OUT", "w", stdout);

    ull n;
    std::cin >> n;

    // 1^3 + 2^3 + 3^3 +... +n^3 = (1 + 2 + 3 +... + n)^2 = n^2*(n+1)^2/4
    n %= MOD;
    std::cout << ((n*(n+1)/2)*(n*(n+1)/2)) % MOD;
    return 0;
}