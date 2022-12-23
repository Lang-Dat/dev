#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHECK.INP", "r", stdin);
    freopen("./CHECK.OUT", "w", stdout);

    int n;
    std::cin >> n;
    if (n % 10 + n % 100 / 10 == n % 1000 / 100 + n % 10000 / 1000)
        std::cout << "YES";
    else std::cout << "NO";

    return 0;
}