// #pragma GCC optimize("O2")
#include <iostream>

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("TIMSO.INP", "r", stdin);
    freopen("TIMSO.OUT", "w", stdout);

    int n;
    std::cin >> n;

    if (n >= 2) std::cout << 2;

    for (int i = 3; n; i += 2) {
        if (isPrime(i)) std::cout << i;
        n--;
    }
    return 0;
}