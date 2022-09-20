#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TONGBP.INP", "r", stdin);
    freopen("./TONGBP.OUT", "w", stdout);

    long long t, n;
    std::cin >> t;
    while(std::cin >> n)
        std::cout << n * (n+1) * (2*n + 1) / 6 << "\n";

    return 0;
} 