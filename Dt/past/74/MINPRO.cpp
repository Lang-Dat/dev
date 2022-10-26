/**
 *	author: Lang Dat
 *	create: 26-10-2022 12:00:09
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
ull t, a, b, x, y, n;

ull minPro(ull a, ull x, ull b, ull y, ull n) {
    ull tmp = min(a - x, n);
    a -= tmp;
    n -= tmp;
    b -= min(b - y, n);
    return a*b;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MINPRO.INP", "r", stdin);
    freopen("./MINPRO.OUT", "w", stdout);

    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> x >> y >> n;
        ull ans = min(minPro(a, x, b, y, n), minPro(b, y, a, x, n));
        std::cout << ans << "\n";
    }

    return 0;
}