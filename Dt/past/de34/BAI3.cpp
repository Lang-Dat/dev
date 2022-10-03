#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    std::string str;
    std::getline(std::cin, str);
    std::map<char, int> freq;
    for (char tmp : str)
        freq[tmp]++;
    for (auto &p : freq)
        std::cout << p.second << p.first;
    return 0;
}