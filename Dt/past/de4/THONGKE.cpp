#pragma GCC optimize("O2")
#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("THONGKE.INP", "r", stdin);
    freopen("THONGKE.OUT", "w", stdout);

    long long n;
    short tmp;
    std::map<short, long long> diems;

    std::cin >> n;
    while(n--) {
        std::cin >> tmp;
        diems[tmp]++;
    }

    for (const auto &tmp : diems) {
        std::cout << tmp.first << " " << tmp.second << "\n";
    }

    return 0;
}