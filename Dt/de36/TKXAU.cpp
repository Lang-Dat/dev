#pragma GCC optimize("O2")
#include <iostream>
#include <map>

std::map<char, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TKXAU.INP", "r", stdin);
    freopen("./TKXAU.OUT", "w", stdout);

    char c;
    while (std::cin >> c)
        freq[c]++;
    for (auto &p : freq)
        std::cout << p.first << ":" << p.second << "\n";

    return 0;
}