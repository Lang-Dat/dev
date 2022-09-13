#pragma GCC optimize("O2")
#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("Nhansu.INP", "r", stdin);
    freopen("Nhansu.OUT", "w", stdout);

    int n, tmp;
    std::set<int> s;
    std::cin >> n;
    while(std::cin >> tmp)
        s.insert(tmp);

    for (auto &nhansu : s)
        std::cout << nhansu << " "; 
    return 0;
}