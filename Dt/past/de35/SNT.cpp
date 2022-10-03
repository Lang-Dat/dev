#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

bool isPrime(int n) {
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
    freopen("./SNT.INP", "r", stdin);
    freopen("./SNT.OUT", "w", stdout);

    int n, a = 1, b = 2;
    std::cin >> n;
    while (b <= n) {
        if (isPrime(b)) std::cout << b << " ";
        ull tmp = b;
        b += a;
        a = tmp;
    }

    return 0;
}