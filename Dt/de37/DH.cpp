#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DH.INP", "r", stdin);
    freopen("./DH.OUT", "w", stdout);

    int h, p, s;
    std::cin >> h >> p >> s;
    s += 1;

    if (s == 60) {
        s = 0;
        p += 1;
        if (p == 60) {
            p = 0;
            if (h < 23) h += 1;
            else if (h == 23) h = 0;
        }
    }
    std::cout << h << " " << p << " " << s;
    return 0;
}