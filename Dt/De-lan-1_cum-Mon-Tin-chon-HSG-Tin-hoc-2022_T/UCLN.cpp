#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UCLN.INP", "r", stdin);
    freopen("./UCLN.OUT", "w", stdout);

    int n, tmp, prev;
    std::cin >> n >> prev;
    if (n <= 1) {
        std::cout << prev << " ";
        return 0;
    }
    while (std::cin >> tmp)
        prev = std::__gcd(tmp, prev);
    std::cout << prev << " ";
    return 0;
}