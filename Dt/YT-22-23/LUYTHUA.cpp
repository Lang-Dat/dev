#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LUYTHUA.INP", "r", stdin);
    freopen("./LUYTHUA.OUT", "w", stdout);

    ull a, n, d, S = 1;
    std:: cin >> a >> n >> d;

    for (int i = 1; i <= n; i++) {
        S += std::pow(a, i*d);
    }
    std::cout << S;
    return 0;
}