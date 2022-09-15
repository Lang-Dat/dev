#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BCAKE.INP", "r", stdin);
    freopen("./BCAKE.OUT", "w", stdout);

    int n, r, h;
    std::cin >> n;
    long double theTich[n];
    for (int i = 0; i < n; i++) {
        std::cin >> r >> h;
        theTich[i] = r*r*h*PI;
    }
    for (auto i : theTich)
        std::cout << i << " ";

    return 0;
}