/**
 *	author: Lang Dat
 *	create: 26-10-2022 37:14:09
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./HINHVUONG.INP", "r", stdin);
    freopen("./HINHVUONG.OUT", "w", stdout);

    ull a;
    std::cin >> a;
    std::cout << a*a*2;

    return 0;
}