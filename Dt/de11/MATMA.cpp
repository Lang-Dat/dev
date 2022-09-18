#pragma GCC optimize("O2")
#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MATMA.INP", "r", stdin);
    freopen("./MATMA.OUT", "w", stdout);

    std::map<char, int> count;
    char c;
    while (std::cin >> c)
        count[c]++;
        
    int j = 0;
    for (auto i = count.begin(); i != count.end() && j < 4; i++)
        if (i->second < 10) {
            std::cout << i->second << "";
            j++;
        }
    return 0;
}