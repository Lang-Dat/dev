/**
 *	author: Lang Dat
 *	create: 08-11-2022 49:49:15
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

ull decreasing(ull &n, ull i) {
    ull tmp = 0;
    while (n % i == 0) {
        tmp++;
        n /= i;
    }
    return tmp + 1;
}
ull soUoc(ull n) {
    ull so_uoc = 1;
    so_uoc *= decreasing(n, 2);
    so_uoc *= decreasing(n, 3);
    for (int i = 5; i * i <= n; i += 6) {
        so_uoc *= decreasing(n, i);
        so_uoc *= decreasing(n, i + 2);
    }
    if (n > 1) so_uoc *= 2;
    return so_uoc;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./UOC.INP", "r", stdin);
    freopen("./UOC.OUT", "w", stdout);
    #endif

    ull n;
    std::cin >> n;
    std::cout << soUoc(n) << "";

    return 0;
}