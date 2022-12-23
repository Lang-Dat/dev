#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SINHNHAT.INP", "r", stdin);
    freopen("./SINHNHAT.OUT", "w", stdout);

    int n, m;
    short cost[m+1];
    for (int i = 1; i <= m; i++) std::cin >> cost[i];
    std::string str;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, str);
        std::stringstream in(str);
        while (in >> tmp)
    }
    return 0;
}