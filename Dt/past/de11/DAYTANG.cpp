#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYTANG.INP", "r", stdin);
    freopen("./DAYTANG.OUT", "w", stdout);

    int max = 1, currMax = 1, n, truoc, sau;
    std::cin >> n >> truoc;
    for (int i = 1; i < n; i++) {
        std::cin >> sau;
        if (sau > truoc) currMax++;
        else currMax = 1;
        truoc = sau;
        if (currMax > max) max = currMax;
    }
    std::cout << max;

    return 0;
}