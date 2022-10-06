#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    std::unordered_map<int, int> freq;
    int n, tmp;
    ull ans = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        freq[tmp]++;
    
    for (auto &p : freq)
        ans += (ull)(p.second - 1) * (ull)p.second / 2;
    std::cout << ans;

    return 0;
}