/**
 *	author: Lang Dat
 *	create: 01-11-2022 49:42:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./OVUONG.INP", "r", stdin);
    freopen("./OVUONG.OUT", "w", stdout);

    ull n, m;
    std::cin >> n >> m;

    ull ucln = __gcd(n, m);
    std::cout << ucln << "\n" << n / ucln << " " << m / ucln;

    return 0;
}