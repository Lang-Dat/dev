/**
 *	author: Lang Dat
 *	create: 08-11-2022 22:14:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PARADE.INP", "r", stdin);
    freopen("./PARADE.OUT", "w", stdout);
    #endif

    int n, l, r, best = 0, sum = 0;
    std::cin >> n;
    while (std::cin >> l >> r) {
        int tmp = std::abs(l-r);
        best = max(best, tmp);
        sum += tmp;
    } 
    std::cout << sum - best << "";
    return 0;
}