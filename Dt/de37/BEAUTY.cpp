#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>

#define ull unsigned long long

const int LIM = 1500; // 9*9*18 = 1458
std::vector<bool> isPrime(LIM, true);

void sieve() {
    isPrime[1] = false;
    isPrime[0] = false;
    for (int i = 2; i * i <= LIM; i++) {
        if (isPrime[i])
            for (int j = i * i; j < LIM; j += i)
                isPrime[j] = false;
    }
}
ull tongChuSo(ull n, ull sum = 0) {
    while(n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return isPrime[sum];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BEAUTY.INP", "r", stdin);
    freopen("./BEAUTY.OUT", "w", stdout);

    sieve();
    ull n, count = 0, i;
    std::cin >> n;

    for (i = 2; count < n; i++)
        if (tongChuSo(i)) {
            count++;
        }
    std::cout << --i;
    return 0;
}