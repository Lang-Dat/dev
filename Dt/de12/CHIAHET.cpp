#pragma GCC optimize("O2")
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHIAHET.INP", "r", stdin);
    freopen("./CHIAHET.OUT", "w", stdout);

    long long a, b, x, y;
    std::cin >> a >> b >> x >> y;
    long long bcnn = x * y / __gcd(x, y);
    if (a == b && (a % y == 0 || a % x == 0)) {
        std::cout << 1;
        return 0;
    }
    // std::cout << b/x - a/x + b/y - a/y - (b/bcnn - a/bcnn);
    std::cout << b/x - a/x + b/y - a/y - (b/bcnn - a/bcnn);
    
    return 0;
}