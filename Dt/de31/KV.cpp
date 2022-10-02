#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KV.INP", "r", stdin);
    freopen("./KV.OUT", "w", stdout);

    int n, m;
    std::cin >> m >> n;
    std::vector<int> trai(m);
    std::vector<int> gai(n);
    for (int i = 0; i < m; i++) std::cin >> trai[i];
    for (int i = 0; i < n; i++) std::cin >> gai[i];
    std::sort(trai.begin(), trai.end());
    std::sort(gai.begin(), gai.end());
    while(!trai.empty()) {
        while (trai.back() < gai.back() && !gai.empty()) gai.pop_back();
        if (gai.empty()) break;
        trai.pop_back();
    }
    if (trai.empty()) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}