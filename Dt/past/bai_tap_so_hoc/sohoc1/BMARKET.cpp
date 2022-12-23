/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 33:25:15
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BMARKET.INP", "r", stdin);
    freopen("./BMARKET.OUT", "w", stdout);
    #endif

    int64_t y, n, k;
    std::cin >> y >> k >> n;

    bool isPrinted = false;

    for (int i = y/k*k + k - y; i + y <= n; i += k) {
        isPrinted = true;
        std::cout << i << " ";
    }
    if (!isPrinted) std::cout << -1 << "";
    return 0;
}