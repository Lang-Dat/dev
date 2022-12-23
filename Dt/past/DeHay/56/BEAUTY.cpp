/**
 *	author: Lang Dat
 *	create: 13.10.2022 29.25.07
**/
#include <iostream>
#include <vector>
using namespace std;

#define ull unsigned long long

const int LIM = 9*9*18 + 10;
const int LIM_SIZE = 1e6 + 1;
ull dp[LIM_SIZE];
std::vector<bool> isPrime(LIM, true);

void sieve() {
    isPrime[1] = false;
    for (int p = 2; p * p <= LIM; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= LIM; i += p)
                isPrime[i] = false;
        }
    }
}
int tongChuSo(ull n, ull sum = 0) {
    while(n > 0) {
        sum += (n % 10)*(n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BEAUTY.INP", "r", stdin);
    freopen("./BEAUTY.OUT", "w", stdout);

    sieve();
    ull n, i = 1, count = 0;
    while (std::cin >> n) {
        if (count >= n) {
            std::cout << dp[n] << "\n";
            continue;
        }
        for (; count < n; i++) {
            if (isPrime[tongChuSo(i)]) {
                count++;
                dp[count] = i;
            }
        }
        std::cout << i - 1 << "\n";
    }
    return 0;
}