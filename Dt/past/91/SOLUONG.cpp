/**
 *	author: Lang Dat
 *	create: 07-11-2022 00:43:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SOLUONG.INP", "r", stdin);
    freopen("./SOLUONG.OUT", "w", stdout);
    #endif

    ull a, b, x, y, bcnn;
    std::cin >> a >> b >> x >> y;
    bcnn = x / __gcd(x, y) * y;

    std::cout << b / bcnn - (a-1) / bcnn << "";
    return 0;
}