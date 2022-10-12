/**
 *	author: Lang Dat
 *	create: 12.10.2022 42.08.09
**/
#include <bits/stdc++.h>
#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEM.INP", "r", stdin);
    freopen("./DEM.OUT", "w", stdout);

    ull n, x;    
    std::cin >> n >> x;

    std::cout << n - n / x;

    return 0;
}