/**
 *	author: Lang Dat
 *	create: 01-11-2022 28:51:19
**/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ull unsigned long long

inline bool isPerfect(ull tmp) {
    return sqrt(tmp) * sqrt(tmp) == tmp;
}
const int LIM = 1e6 + 6;
std::vector<int> isPrime(LIM, true);
void sieve() {
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i <= LIM; i++) {
        if (isPrime[i]);
        for (int j = i * i; j < LIM; j += i)
            isPrime[j] = false;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOC.INP", "r", stdin);
    freopen("./UOC.OUT", "w", stdout);

    ull n, tmp, count = 0;
    std::cin >> n;
    sieve();
    while (std::cin >> tmp) {
        if (isPerfect(tmp) && isPrime[sqrt(tmp)])
            count++;
    }
    std::cout << count << "";
    return 0;
}