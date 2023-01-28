/**
 *	author : Lăng Trọng Đạt
 *	creater: 28-01-2023 07:58:54
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DAYSO.INP", "r", stdin);
    freopen("./DAYSO.OUT", "w", stdout);
    #endif

    uint64_t n;
    std::cin >> n;
    std::cout << n*(n + 1) / 2 << "";

    return 0;
}