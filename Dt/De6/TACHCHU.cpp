#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("TACHCHU.INP", "r", stdin);
    freopen("TACHCHU.OUT", "w", stdout);

    char c;
    std::map<char, int> count;
    while (std::cin >> c)
            count[std::toupper(c)]++;
    bool isPrint = false;
    for (auto &itr : count) {
        if (itr.second == 1 && itr.first != ' ') {
            isPrint = true;
            std::cout << itr.first << "\n";
        }
    }
    if (!isPrint)
        std::cout << -1;
    return 0;
}