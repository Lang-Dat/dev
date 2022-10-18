/**
 *	author: Lang Dat
 *	create: 16-10-2022 24:38:19
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYXICH.INP", "r", stdin);
    freopen("./DAYXICH.OUT", "w", stdout);

    ull d, r, n;
    std::cin >> d >> r >> n;
    std::cout << n*2*r + 2*d;

    return 0;
}