/**
 *	author: Lang Dat
 *	create: 27-10-2022 07:34:20
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

ull numberOfPaths(ull m, ull n)
{
    // We have to calculate m+n-2 C n-1 here
    // which will be (m+n-2)! / (n-1)! (m-1)!
    ull path = 1;
    for (ull i = n; i < (m + n - 1); i++) {
        path *= i;
        path /= (i - n + 1);
    }
    return path;
}
 

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DUONGDI.INP", "r", stdin);
    freopen("./VinhV3/DUONGDI/Test11/DUONGDI.INP", "r", stdin);
    // freopen("./DUONGDI.OUT", "w", stdout);

    ull n;
    std::cin >> n;
    std::cout << numberOfPaths(n, n) << "";

    return 0;
}