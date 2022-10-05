#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DIV3.INP", "r", stdin);
    freopen("./DIV3.OUT", "w", stdout);

    ull n, tmp, chiaHet = 0, du1 = 0, du2 = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        if (tmp % 3 == 0) chiaHet++;
        else if (tmp % 3 == 1) du1++;
        else if (tmp % 3 == 2) du2++;
    std::cout << chiaHet*(chiaHet-1)/2 + du1 * du2;
    return 0;
}