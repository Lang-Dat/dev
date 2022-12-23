#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOAM.INP", "r", stdin);
    freopen("./SOAM.OUT", "w", stdout);

    int n, tmp, max = INT32_MIN;
    std::cin >> n;
    while(std::cin >> tmp)
        if (tmp < 0 && tmp > max)
            max = tmp;
    (max == INT32_MIN) ? std::cout << 0 : std::cout << max;

    return 0;
}