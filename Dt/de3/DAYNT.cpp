#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <set>

bool isPrime(int n) {
    if (n <= 1) return false;
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
    freopen("DAYNT.INP", "r", stdin);
    freopen("DAYNT.OUT", "w", stdout);

    int n, a;
    std::set<int> s;
    std::cin >> n;
    
    while (n--)
    {
        std::cin >> a;
        if (isPrime(a))
            s.insert(a);
    }

    for (auto &p : s)
        std::cout << p << " ";
    
    return 0;
}