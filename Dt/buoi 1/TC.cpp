#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("TC.INP", "r", stdin);
    freopen("TC.OUT", "w", stdout);

    std::string str;
    std::cin >> str;

    int ans = 0;

    for (char c : str)
        ans += (int)(c - '0');

    if (ans % 2 == 0 ) std::cout << "Yes";
    else std::cout << "No";
    
    return 0;
}