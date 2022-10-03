#pragma GCC optimize("O2")
#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    char tmp;
    std::map<char, int> freq;
    while(std::cin >> tmp)
        freq[tmp]++;
    for (auto &p : freq)
        std::cout << p.second << "" << p.first;
    return 0;
}