/**
 *	author: Lang Dat
 *	create: 31-10-2022 22:45:07
**/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ull unsigned long long

int decresingN(ull &n, ull i) {
    ull tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    return tmp;
}
int phanTichN(ull n) {
    ull count = 1;
    count *= 1 + decresingN(n, 2);
    count *= 1 + decresingN(n, 3);
    for (ull i = 5; i * i <= n; i += 6) {
        count *= 1 + decresingN(n, i);
        count *= 1 + decresingN(n, i+2);
    }
    if (n > 1) count *= 2;
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MATONG.INP", "r", stdin);
    freopen("./Test/MATONG/TEST09/MATONG.INP", "r", stdin);
    // freopen("./MATONG.OUT", "w", stdout);

    ull n, ans = 0, tmp;
    // sieve();
    std::cin >> n;
    while (std::cin >> tmp) {
        ans += tmp*phanTichN(tmp);
    }

    std::cout << ans << "";
    return 0;
}