/**
 *	author: Lang Dat
 *	create: 31-10-2022 51:38:07
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BSBB.INP", "r", stdin);
    freopen("./BSBB.OUT", "w", stdout);

    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        ans += n / i;
        if (n % i == 0) ans--;
    }

    std::cout << ans << "";
    return 0;
}