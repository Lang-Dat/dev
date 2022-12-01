/**
 *	author: Lăng Trọng Đạt
 *	create: 01-12-2022 27:24:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CAU1.INP", "r", stdin);
    freopen("./CAU1_trau.OUT", "w", stdout);
    #endif

    int64_t n, ans = 0;
    std::cin >> n;
    for (int i = 2; i <= n; i += 2)
        ans += i;
    for (int i = 1; i <= n; i += 2)
        ans -= i;
    std::cout << ans << "";
    return 0;
}