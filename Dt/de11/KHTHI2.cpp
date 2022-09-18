#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KYTHI.INP", "r", stdin);
    freopen("./KYTHI.OUT", "w", stdout);

    int x, y, z, n, min = INT32_MAX, diemDat;
    std::cin >> n;
    std::vector<int> cost(n + 1, 0);
    while(std::cin >> x >> y >> z) {
        cost[x] += z;
        cost[y] += z;
    }
    for (int i = 1; i <= n; i++) {
        if (cost[i] <= min) {
            diemDat = i;
            min = cost[i];
        }
    }
    std::cout << diemDat << "\n" << min;
    return 0;
}