#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("UCLN.INP", "r", stdin);
    freopen("UCLN.OUT", "w", stdout);

    short n, tmp, first;

    std::cin >> n >> first;
    n--;
    while (n--)
    {
        std::cin >> tmp;
        first = std::__gcd(tmp, first);
    }
    std::cout << first;
    
    return 0;
}