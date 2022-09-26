#pragma GCC optimize("O2")
#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int n;
    std::cin >> n;
    std::map<long double, std::pair<int, int>> mp = {{0, {0, 1}}, {1, {1, 1}}};
    for (long double i = 0; i <= n; i++)
        for (long double j = i + 1; j <= n; j++)
            if (!mp.count((long double)(i / j)))
                mp[(long double)(i / j)] = {i, j};
    for (auto &itr : mp)
        std::cout << itr.second.first << "/" << itr.second.second << " ";
    std::cout << "\n" << mp.size();
    return 0;
}