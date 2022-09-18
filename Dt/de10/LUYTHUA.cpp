#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LUYTHUA.INP", "r", stdin);
    freopen("./LUYTHUA.OUT", "w", stdout);

    long long a, b;
    std::cin >> a >> b;
    a = a % 10;

    if (b < 4)
        std::cout << (int)std::pow(a, b) % 10 << " ";
    else if (a == 1 || a == 5 || a == 6 || a == 0)
        std::cout << a;
    else if (a == 7 || a == 9 || a == 3)
        std::cout << (int)std::pow(a, b%4) % 10 << " ";
    else if (a == 2 || a == 4 || a == 8)
        std::cout << (6*(int)std::pow(a, b%4)) % 10 << " ";
    return 0;
}