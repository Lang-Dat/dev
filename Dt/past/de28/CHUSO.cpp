#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHUSO.INP", "r", stdin);
    freopen("./CHUSO.OUT", "w", stdout);

    char c, max = 0;
    int sum = 0;
    while(std::cin >> c) {
        sum += c - '0';
        if (c > max) max = c;
    }
    std::cout << sum << "\n" << max;
    return 0;
}