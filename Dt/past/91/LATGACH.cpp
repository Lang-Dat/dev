/**
 *	author: Lang Dat
 *	create: 07-11-2022 26:49:07
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LIM = (1e7 + 5);
std::vector<bool> isPrime(LIM, true);

void sieve() {
    isPrime[0] = false;
    for (int i = 2; i * i < LIM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < LIM; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./LATGACH.INP", "r", stdin);
    freopen("./LATGACH.OUT", "w", stdout);
    #endif

    sieve();

    int n, tmp;
    std::vector<int> primes;
    std::cin >> n;
    while (std::cin >> tmp)
        if (isPrime[tmp])
            primes.push_back(tmp);
    n = primes.size();
    if (primes.empty()) {
        std::cout << "-1";
    } else {
        sort(primes.begin(), primes.end());
        for (int i = n - 1 - n % 2; i > 0; i -= 2)
            std::cout << primes[i] << " ";
        for (int i = 0; i < n; i += 2)
            std::cout << primes[i] << " ";
    }
    // 3 7 11 19 23 31: 6
    // 31 19 7 3 11 23 35
    return 0;
}