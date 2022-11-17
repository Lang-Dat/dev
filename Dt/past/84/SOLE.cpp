/**
 *	author: Lang Dat
 *	create: 01-11-2022 05:39:19
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOLE.INP", "r", stdin);
    freopen("./SOLE.OUT", "w", stdout);

    ull n;
    std::cin >> n;

    std::cout << n / 3 - n / 6 << "";

    return 0;
}