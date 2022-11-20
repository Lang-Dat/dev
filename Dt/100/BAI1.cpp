/**
 *	author: Lang Dat
 *	create: 18-11-2022 34:02:19
**/
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 1e5 + 6;
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
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    sieve(LIM);
    int n, count = 0;
    std::cin >> n;
    for (int i = n; i >= n / 2; i--) {
        if (isPrime[i] && isPrime[n - i])
            count++;
    }
    std::cout << count << "";
    return 0;
}