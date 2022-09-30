#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

bool isPerfect(int n) {
    int tongUoc = 1;
    for (int i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0 && i * i != n) tongUoc += i + n/i;
        else if (n % i == 0 && i * i == n) tongUoc += i;
    return tongUoc == n; 
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SHH.INP", "r", stdin);
    freopen("./SHH.OUT", "w", stdout);

    int n, ans = 0;
    std::cin >> n;
    for (int i = 2; i <= n; i++)
        if (isPerfect(i))
            ans += i;
    std::cout << ans;
    return 0;
}