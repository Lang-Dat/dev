#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CSN.INP", "r", stdin);
    freopen("./CSN.OUT", "w", stdout);

    int L, G, min = INT32_MAX, a, b;
    std::cin >> L >> G;
    for (int i = L; i <= G; i += L)
        for (int j = L; j <= G && i / L * j <= G; j += L)
            if (i / L * j == G) {
                if (min > i + j) {
                    min = i + j;
                    a = i; b = j;
                }
                break;
            } 

    std::cout << a << " " << b;
    return 0;
}