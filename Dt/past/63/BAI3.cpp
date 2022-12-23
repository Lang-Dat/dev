/**
 *	author: Lang Dat
 *	create: 20-10-2022 17:54:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

int g[5];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

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