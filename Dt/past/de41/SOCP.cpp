#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

inline bool isPerfectSQ(ull n) {
    return (int)std::sqrt(n) * (int)std::sqrt(n) == n;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOCP.INP", "r", stdin);
    freopen("./SOCP.OUT", "w", stdout);

    ull L, R;
    std::cin >> L >> R;

    if (isPerfectSQ(L))
        std::cout << (int)std::sqrt(R) - (int)std::sqrt(L) + 1;
    else 
        std::cout << (int)std::sqrt(R) - (int)std::sqrt(L);

    return 0;
}