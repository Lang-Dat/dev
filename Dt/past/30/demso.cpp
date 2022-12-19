/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 32:25:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./demso.OUT", "w", stdout);
    freopen("./demso.INP", "r", stdin);
    #endif

    int64_t l, r, c;
    std::cin >> l >> r >> c;

    std::cout << (r - l + 1) - (r/c - (l-1)/c) << "";

    return 0;
}