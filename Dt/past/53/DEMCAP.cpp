/**
 *	author: Lang Dat
 *	create: 12.10.2022 05.23.09
**/
#include <bits/stdc++.h>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMCAP.INP", "r", stdin);
    freopen("./DEMCAP.OUT", "w", stdout);

    ull n, so_chan = 0, so_le = 0, tmp;
    std::cin >> n;
    while(std::cin >> tmp)
        if (tmp % 2 == 0) so_chan++;
        else so_le++;
    std::cout << so_chan*(so_chan-1)/2 + so_le*(so_le-1)/2;
    return 0;
}