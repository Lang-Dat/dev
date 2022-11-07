/**
 *	author: Lang Dat
 *	create: 07-11-2022 12:41:14
**/
#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./QUYENGOP.INP", "r", stdin);
    freopen("./QUYENGOP.OUT", "w", stdout);
    #endif

    ull n;
    std::cin >> n;
    int x = sqrt(n);
    std::cout << n*(n + 1)/2 - x*(x + 1)*(2*x + 1) / 6 << "";

    return 0;
}