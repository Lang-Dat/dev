#pragma GCC optimize("O2")
#include <iostream>
#include <map>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    std::map<char, int> mp;
    std::string str;
    std::getline(std::cin, str);
    for (char c : str)
        mp[std::toupper(c)]++;

    std::cout << mp.size() << "\n";
    for (auto i : mp) {
        std::cout << i.first << " " << i.second << "\n";
    }
    return 0;
}