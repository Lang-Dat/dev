/**
 *	author: Lăng Trọng Đạt
 *	create: 26-11-2022 16:25:21
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
    freopen("./SQ.INP", "r", stdin);
    freopen("./SQ.OUT", "w", stdout);
    #endif

    uint64_t a, b, n, ans = 0;
    std::cin >> a >> b >> n;

    if (a > b) a -= a / b * b;
    while (n-- && a % b != 0) {
        a *= 10;
        if (a > b) {
            ans += a / b;
            a -= a / b * b;
        }
    }
    std::cout << ans + a / b << "";
    return 0;
}