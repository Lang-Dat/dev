#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./thamquan.INP", "r", stdin);
    freopen("./thamquan.OUT", "w", stdout);

    ull x, res;
    std::cin >> x;
    res = x / 9;
    if (x % 9 != 0) res++;
    std::cout << res;
    return 0;
}