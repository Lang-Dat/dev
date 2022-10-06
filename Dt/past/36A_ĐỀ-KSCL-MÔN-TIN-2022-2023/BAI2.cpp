#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    std::string str;
    std::vector<std::string> string;
    while (std::cin >> str)
        string.push_back(str);
    for (std::string s : string)
        if (s != string.back())
            std::cout << s << " ";

    return 0;
}