#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ANHHOA.INP", "r", stdin);
    freopen("./ANHHOA.OUT", "w", stdout);

    int n, a, b, c, len = 0, max = 1;
    std::cin >> n >> a >> b;
    if (n <= 2) {
        std::cout << n;
        return 0;
    }
    while(std::cin >> c) {
        if (c == b && c == a) len = 2;
        else len++;
        if (len > max) max = len;
        a = b;
        b = c;
    }
    std::cout << max;
    return 0;
}