#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <unordered_set>

inline bool isPerfect(int n) {
    return n == (int)(std::sqrt(n)) * (int)(std::sqrt(n));
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CP.INP", "r", stdin);
    freopen("./CP.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    std::unordered_set<int> chinhPhuong;
    while(std::cin >> tmp)
        if (isPerfect(tmp))
            chinhPhuong.insert(tmp);

    for (int i = 0; i <= std::sqrt((int)1e9); i++)
        if (!chinhPhuong.count(i * i)) {
            std::cout << i * i << "";
            return 0;
        }

    return 0;
}