#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>

#define ull unsigned long long

const int LIM = 1e9 + 9;
std::unordered_map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    int n, d, tmp;
    ull ans = 0;

    std::cin >> d >> n;
    while(std::cin >> tmp)    
        freq[tmp % d]++;
    
    for (auto &p : freq)
        ans += (ull)p.second*(ull)(p.second-1) / 2;

    std::cout << ans;
    return 0;
}