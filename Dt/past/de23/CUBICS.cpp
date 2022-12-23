#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

inline ull getSum(ull i) {
    return i * (i + 1) / 2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CUBICS.INP", "r", stdin);
    freopen("./CUBICS.OUT", "w", stdout);

    ull n;
    std::cin >> n;
    std::cout << n * (n + 1) / 2;
    return 0;
}