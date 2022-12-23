#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

bool isPrime(int n) {
    if (n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("NT.INP", "r", stdin);
    freopen("NT.OUT", "w", stdout);

    int n;
    std::cin >> n;
    long long s = 0;
    if (n >= 2) {
        std::cout << 2 << " ";
        s += 2;
    }
    for (int i = 3; i < n; i += 2) {
        if (isPrime(i)) {
            std::cout << i << " ";
            s += i;
        }
    }
    std::cout << "\n" << s;
    return 0;
}