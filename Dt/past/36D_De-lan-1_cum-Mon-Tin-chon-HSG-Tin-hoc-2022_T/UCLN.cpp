#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UCLN.INP", "r", stdin);
    freopen("./UCLN.OUT", "w", stdout);

    int n, tmp, ucln;
    std::cin >> n >> ucln;
    while(std::cin >> tmp)
        ucln = std::__gcd(ucln, tmp);
    std::cout << ucln;

    return 0;
}