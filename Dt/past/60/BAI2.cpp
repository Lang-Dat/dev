/**
 *	author: Lang Dat
 *	create: 16.10.2022 57.44.10
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        ans += n/i;
        if (n % i == 0) ans--;
    }
    std::cout << ans;
    return 0;
}