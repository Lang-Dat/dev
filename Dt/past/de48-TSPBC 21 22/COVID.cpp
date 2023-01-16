#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int g[5];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./COVID.INP", "r", stdin);
    // freopen("./TestPBC2021_2022/COVID/Test13/COVID.INP", "r", stdin);
    freopen("./COVID.OUT", "w", stdout);


    // int n, tmp;
    // std::cin >> n;
    // while (std::cin >> tmp) {
    //     g[tmp]++;
    // }

    // int count = std::min(g[1], g[3]);
    // count += g[3] - count;
    // g[1] -= count;
    // if (g[1] > 0) g[2] += g[1] / 2;
    // count += g[2] / 2 + g[4];
    // if (g[2] % 2 || (g[1] % 1 && g[1] > 0)) count++;
    // std::cout << count;
    int n, tmp, count = 0;   
    std::cin >> n;
    while(std::cin >> tmp)
        g[tmp]++;
    count += std::min(g[1], g[3]);
    count += g[3] - count;
    g[1] -= count;
    g[2] += (g[1] > 0) ? g[1] / 2 : 0;
    count += g[2] / 2;
    if (g[2] % 2 || g[1] % 2) count++;
    count += g[4];
    std::cout << count;
    return 0;
}