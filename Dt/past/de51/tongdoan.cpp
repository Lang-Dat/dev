#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./tongdoan.INP", "r", stdin);
    freopen("./tongdoan.OUT", "w", stdout);

    ull a, b;
    std::cin >> a >> b;

    std::cout << (b-a+1)*(b+a)/2;

    return 0;
}