#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MUACO.INP", "r", stdin);
    freopen("./MUACO.OUT", "w", stdout);

    ull n, k, p;
    std::cin >> p >> n >> k;
    if (k*n*(n+1) / 2 <= p)
        std::cout << "YES";
    else 
        std::cout << "NO\n" << k*n*(n+1) / 2 - p;
    return 0;
}