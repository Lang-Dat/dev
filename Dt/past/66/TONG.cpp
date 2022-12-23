/**
 *	author: Lang Dat
 *	create: 21-10-2022 55:16:20
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

const int LIM = 1e6 + 6;
const ull MOD = 1e18;
ull nums[LIM];
ull n, p, k, sum = 0, ans = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TONG.INP", "r", stdin);
    freopen("./TONG.OUT", "w", stdout);

    std::cin >> n >> k >> p;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    p--;
    p %= n;
    for (int i = p; i < n && k > 0; i++, k--) {
        ans += nums[i];
    }
    if (k < 0) {
        std::cout << ans;
        return 0;
    }
    ans += ((sum % MOD) * ((k / n) % MOD)) % MOD;
    k %= n;
    for (int i = 0; i < k; i++) {
        ans += nums[i];
    }
    std::cout << ans;
    return 0;
}