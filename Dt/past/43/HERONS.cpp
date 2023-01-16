/**
 *	author: Lăng Trọng Đạt
 *	create: 31-12-2022 35:11:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./HERONS.INP", "r", stdin);
    freopen("./HERONS.OUT", "w", stdout);
    #endif

    int a, b;
    std::cin >> a >> b;

    std::cout << max(a, b) / 2 + (max(a, b) & 1) << " " << min(a, b);

    return 0;
}