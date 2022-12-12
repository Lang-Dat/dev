/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 53:26:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GCDMAX.INP", "r", stdin);
    freopen("./GCDMAX.OUT", "w", stdout);
    #endif

    int t, n;
    std::cin >> t;
    while (std::cin >> n)
        std::cout << n / 2 << "\n";

    return 0;
}