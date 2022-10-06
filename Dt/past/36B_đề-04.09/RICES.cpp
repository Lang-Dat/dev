#pragma GCC optimize("O2")
#include <iostream>

// const int type1 = 5, type2 = 3;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./RICES.INP", "r", stdin);
    freopen("./RICES.OUT", "w", stdout);

    int n;
    std::cin >> n;
    
    int tui5 = n / 5;
    int tui3 = (n-tui5*5) / 3;
    int remind = n - tui3*3 - tui5*5;
    if (remind == 1 && tui5 > 0) tui3++;
    else if (remind == 2 && tui5 >= 2) tui3 += 4 - 2;
    else if (remind != 0) {
        std::cout << -1;
        return 0;
    }
    std::cout << tui3 + tui5;
    return 0;
}