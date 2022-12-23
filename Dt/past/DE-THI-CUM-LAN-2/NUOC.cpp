#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 100;
int costs[LIM + 1];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NUOC.INP", "r", stdin);
    freopen("./NUOC.OUT", "w", stdout);

    int n, x, y, c, diemDat, min = INT32_MAX;
    std::cin >> n;
    while(std::cin >> x >> y >> c) {
        costs[x] += c;
        costs[y] += c;
    }  

    for (int i = 0; i <= LIM; i++)
        if (costs[i] != 0 && costs[i] < min) {
            min = costs[i];
            diemDat = i;
        }
    std::cout << diemDat << "\n" << min;
    return 0;
}