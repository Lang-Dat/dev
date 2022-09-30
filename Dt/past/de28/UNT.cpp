#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define ull unsigned long long

bool isPrime(ull n) {
    if (n < 4) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ull i = 5; i <= std::sqrt(n); i += 6) 
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UNT.INP", "r", stdin);
    freopen("./UNT.OUT", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> prime;
    for (int i = 1; i <= std::sqrt(n); i++)
        if (n % i == 0) {
            if (i * i != n && isPrime(n / i)) prime.push_back(n / i);
            if (isPrime(i)) prime.push_back(i);
        }
    std::sort(prime.begin(), prime.end());
    for (int i : prime)
        std::cout << i << " ";
    return 0;
}