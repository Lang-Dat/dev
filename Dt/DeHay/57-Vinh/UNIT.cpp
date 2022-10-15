/**
 *	author: Lang Dat
 *	create: 14.10.2022 41.45.19
**/
#include <iostream>
using namespace std;

#define ull long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UNIT.INP", "r", stdin);
    freopen("./test_TT/UNIT/Test09/UNIT.INP", "r", stdin);
    freopen("./UNIT.OUT", "w", stdout);

    ull n, q, m, l;
    std::cin >> n >> q >> m >> l; // 255 9 9
    for (int i = 1; i < l; i++) {
        if (n % (q + m) == 0) {
            n = m * n + 1;
        } else {
            n = n * q + 2;
        }
        n = n % (q+m);
    }
    std::cout << n % 10;
    return 0;
}