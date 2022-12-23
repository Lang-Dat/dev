#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BANGNHAU.INP", "r", stdin);
    freopen("./BANGNHAU.OUT", "w", stdout);

    int tmp;
    std::unordered_map<int, int> freq;
    while(std::cin >> tmp)
        freq[tmp]++;
    
    for (const auto &p : freq)
        if (p.second == 4) {
            std::cout << "YES";
            return 0;
        }
    std::cout << "NO";
    

    return 0;
}