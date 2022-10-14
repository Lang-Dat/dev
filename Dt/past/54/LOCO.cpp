/**
 *	author: Lang Dat
 *	create: 12.10.2022 05.49.19
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LOCO.INP", "r", stdin);
    freopen("./TEST/loco/Test01/LOCO.INP", "r", stdin);
    // freopen("./LOCO.OUT", "w", stdout);

    ull a = 1, b = 2, c = 4, n, m;
    std::cin >> n >> m;

    for (int i = 3; i < n; i++) {
        int tmp = c;
        c += a + b;
        a = b;
        b = tmp;
        c %= m;
    }
    std::cout << c;
    return 0;
}