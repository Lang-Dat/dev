#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    std::string best = "", tmp;
    while(std::cin >> tmp) {
        if (tmp.size() >= best.size())
            best = tmp;
    }
    std::cout << best;
    return 0;
}