#pragma GCC optimize("O2")
#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("LAPTRINH.INP", "r", stdin);
    freopen("LAPTRINH.OUT", "w", stdout);

    int n, a;
    std::map<int, int> mp;
    std::cin >> n;
    while (n--)
    {
        std::cin >> a;
        mp[a]++;
    }

    auto itr = *(mp.begin());
    std::cout << itr.first << "\n" << itr.second;
    

    return 0;
}