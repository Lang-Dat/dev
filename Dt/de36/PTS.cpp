#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PTS.INP", "r", stdin);
    freopen("./PTS.OUT", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 2; i < n; i++)
        while (n % i == 0) {
            std::cout << i << ".";
            n /= i;
        }
    if (n > 1)
        std::cout << n << ".";

    return 0;
}