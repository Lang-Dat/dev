#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHIAHET.INP", "r", stdin);
    freopen("./CHIAHET.OUT", "w", stdout);

    int a, b, x, y;
    std::cin >> a >> b >> x >> y;
    std::cout << b/x + b/y - a/x - a/y - (b/(x*y) - a/(x*y)) << " ";

    return 0;
}