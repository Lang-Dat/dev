#pragma GCC optimize("O2")
#include <iostream>
#include <set>

std::set<char> getInitChar(std::string str) {
    return std::set<char>(str.begin(), str.end());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    std::string s1, s2;
    while (std::cin >> s1 >> s2)
        if (getInitChar(s1) == getInitChar(s2))
            std::cout << "YES\n";
        else 
            std::cout << "NO\n";


    return 0;
}