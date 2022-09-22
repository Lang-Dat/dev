#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TRONGCAY.INP", "r", stdin);
    freopen("./TRONGCAY.OUT", "w", stdout);
    int n, tmp;
    std::vector<int> primes;
    std::cin >> n;
    while(std::cin >> tmp)
        if (isPrime(tmp))
            primes.push_back(tmp);

    if (primes.size() == 0) {
        std::cout << -1;
        return 0;
    }

    std::sort(primes.begin(), primes.end(), std::greater<int>());
    std::deque<int> res;
    for (int i = 0; i < primes.size(); i++)
        (i % 2 == 0) ? res.push_back(primes[i]) : res.push_front(primes[i]);

    for (int i : res) 
        std::cout << i << " ";
    return 0;
}