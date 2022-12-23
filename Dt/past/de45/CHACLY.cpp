#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 46340; // 46340*46340 = 2^31 - Limit
bool canGo[LIM][LIM];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./CHACLY.INP", "r", stdin);
    // freopen("./CHACLY.OUT", "w", stdout);

    int n, m, x, y;
    std::cin >> n >> m;
    while (std::cin >> x >> y) {
        canGo[x][y] = true;
        canGo[y][x] = true;
    }

    return 0;
}