#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>

#define ull unsigned long long

const int LIM = 1e5;
std::vector<bool> isPrime(LIM, true);

void sieve(ull n) {
	for (ull p = 2; p <= std::sqrt(n); p++)
		if (isPrime[p])
			for (ull j = p * p; j <= n; j += p)
				isPrime[j] = false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PRIME.INP", "r", stdin);
    freopen("./PRIME.OUT", "w", stdout);

    ull n, count = 0;
    std::cin >> n;
    sieve(n);
    for (ull i = 2; i <= std::sqrt(n); i++) {
        if (isPrime[i]) count++;
    }
    std::cout << count;
    return 0;
}