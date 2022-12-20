/**
 *	author: Lang Dat
 *	create: 27-10-2022 25:57:19
**/
#include <iostream>
using namespace std;


int solve (long double n, long double m) {
    long double tmp = n / m;
    int ans = 0;
    if (tmp <= 0.5) {
        ans += n * (m / n - 1);
    } else if (tmp > 0.5) {
        ans += n;
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CATGO.INP", "r", stdin);
    freopen("./CATGO.OUT", "w", stdout);


    long double n, m, tmp; // tmp: so go moi phan (so voi mot thanh go ban dau)
    int ans = 0;
    std::cin >> n >> m;
    tmp = n / m;


    if ((int)n % (int)m == 0) {
        ans = 0;
    } else if (tmp > 1) {
        ans += solve(n - m * (int)tmp, m);
    } else {
        ans += solve(n, m);
    }
    std::cout << ans << "";
    return 0;
}