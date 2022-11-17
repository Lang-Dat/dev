/**
 *	author: Lang Dat
 *	create: 06-11-2022 53:10:19
**/
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 1e6 + 6;
std::vector<bool> isPrime(LIM, true);

void sieve(int n) {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TIMSO.INP", "r", stdin);
    freopen("./TIMSO.OUT", "w", stdout);
    #endif

    sieve(LIM);
    int n;
    std::cin >> n;
    for (int i = 2; n > 0; i++) {
        if (isPrime[i]) {
            n--;
            std::cout << i << "";
        }
    }
    return 0;
}