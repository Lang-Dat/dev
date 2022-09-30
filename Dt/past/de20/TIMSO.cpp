#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

bool isPrime(ull n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TIMSO.INP", "r", stdin);
    freopen("./TIMSO.OUT", "w", stdout);

    int count = 1, n;
    std::cin >> n;
    std::cout << 2;
    for (ull i = 3; count < n; i += 2)
        if (isPrime(i)) {
            std::cout << i;
            count++;
        }

    return 0;
}