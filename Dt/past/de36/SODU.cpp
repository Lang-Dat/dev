#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SODU.INP", "r", stdin);
    freopen("./SODU.OUT", "w", stdout);

    ull a, b, t, x, y;
    std::cin >> a >> b >> t;
    while (std::cin >> x >> y)
        std::cout << (int)((std::pow(a, y + 1) - std::pow(a, x)) / (a - 1)) % b << "\n";

    return 0;
}