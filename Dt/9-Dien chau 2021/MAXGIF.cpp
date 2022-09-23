#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MAXGIF.INP", "r", stdin);
    freopen("./MAXGIF.OUT", "w", stdout);

    int n, prev, tmp, max = 0;
    std::cin >> n >> prev;
    while(std::cin >> tmp) {
        if (tmp + prev > max) max = tmp + prev;
        prev = tmp;
    }
    std::cout << max;

    return 0;
}