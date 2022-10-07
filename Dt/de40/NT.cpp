#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NT.INP", "r", stdin);
    freopen("./NT.OUT", "w", stdout);

    ull T, a, b;
    std::cin >> T;
    while (std::cin >> a >> b)
        if (b - a == 1 && isPrime(a + b)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        
    return 0;
}