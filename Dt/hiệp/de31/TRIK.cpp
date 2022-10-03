#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TRIK.INP", "r", stdin);
    freopen("./TRIK.OUT", "w", stdout);

    char c;
    int curr = 1;
    while(std::cin >> c) {
        if (c == 'A' && curr == 1) curr = 2;
        else if (c == 'A' && curr == 2) curr = 1;
        else if (c == 'B' && curr == 2) curr = 3;
        else if (c == 'B' && curr == 3) curr = 2;
        else if (c == 'C' && curr == 3) curr = 1;
        else if (c == 'C' && curr == 1) curr = 3;
        // log(c, curr)
    }
    std::cout << curr << " ";
    return 0;
}