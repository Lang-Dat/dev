#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("Tongsoam.INP", "r", stdin);
    freopen("Tongsoam.OUT", "w", stdout);

    int n, max = INT32_MIN, tmp;
    std::cin >> n;
    while(n--) {
        std::cin >> tmp;
        // log(tmp, max);
        if (tmp < 0 && tmp > max)
            max = tmp;
    }
    if (max == INT32_MIN)
        std::cout << 0;
    else
        std::cout << max;
    return 0;
}   