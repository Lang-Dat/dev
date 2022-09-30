#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BSBB.INP", "r", stdin);
    freopen("./BSBB.OUT", "w", stdout);

    int n;
    long long ans = 0;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        ans += n / i;
        if (n / i * i == n) ans--;
    }
    std::cout << ans;

    return 0;
}