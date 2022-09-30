#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long
const int MOD = 1e9 + 7;

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
    freopen("./NT.INP", "r", stdin);
    freopen("./NT.OUT", "w", stdout);
    ull l, r, sum = 0, k = 1;
    std::cin >> l >> r;
    if (l < 3) {
        sum += 2;
        k++;
    }
    if (l % 2 == 0) l++;
    for (int i = l; i <= r; i += 2)
        if (isPrime(i)) {
            sum += k * i; 
            k++;
        }
    std::cout << sum % MOD << "\n";
    return 0;
}