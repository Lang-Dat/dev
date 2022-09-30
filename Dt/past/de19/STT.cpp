#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>

bool isFriend(int big, int small) {
    for (int i = 1; i <= std::sqrt(small); i++)
        if ((big % i == 0 && small % i != 0) ||
            (big % i != 0 && small % i == 0) || 
            (small % i == 0 && big % (small / i) != 0) && i != 1)
            return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./STT.INP", "r", stdin);
    freopen("./STT.OUT", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::cout << isFriend(std::max(n, m), std::min(n, m));
    return 0;
}