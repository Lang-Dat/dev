/**
 *	author: Lang Dat
 *	create: 07-11-2022 40:40:07
**/
#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long

ull calc(ull n) {
    return (ull)(pow(n*(n + 1) / 2, 2) + .1);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TONGLP.INP", "r", stdin);
    freopen("./TONGLP.OUT", "w", stdout);
    #endif

    ull t, a, b;
    std::cin >> t;
    while (std::cin >> a >> b) {
        std::cout << calc(b) - calc(a - 1) << "\n";
    }

    return 0;
}