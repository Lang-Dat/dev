#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TONG.INP", "r", stdin);
    freopen("./TONG.OUT", "w", stdout);

    long long n;
    std::cin >> n;
    std::cout << n * n;

    return 0;
}