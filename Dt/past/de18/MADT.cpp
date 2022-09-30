#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

void tongUoc(ull n) {
    ull sum = 0;
    for (int i = 1; i <= std::sqrt(n); i++)
        if (n % i == 0 && i * i != n)
            sum += i + n / i;
        else if (n % i == 0 && i * i == n)
            sum += i;
    std::cout << sum << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./MADT.INP", "r", stdin);
    freopen("./MADT.OUT", "w", stdout);

    int t, n;
    std::cin >> t;
    while(std::cin >> n)   
        tongUoc(n);

    return 0;
}