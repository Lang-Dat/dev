#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    std::string str;
    std::cin >> str;
    std::sort(str.begin(), str.end(), std::greater<int>());
    std::cout << str;
    return 0;
}