/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 03:57:19
**/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
int divisors[LIM], pre_sum[LIM];
bool isPrime[LIM];

void sieveDivisor() {
    // Time complexity: O(nLog2(n)) (n is LIM)
    for (int i = 1; i < LIM; i++)
        for (int j = i; j < LIM; j += i)
            divisors[j]++;
}
void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i * i <= LIM; i++) {
        if (isPrime[i])
        for (int j = i *i; i * j < LIM; j += i)
            isPrime[j] = false;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./uocnto.INP", "r", stdin);
    freopen("./uocnto.OUT", "w", stdout);
    #endif
    
    // preprocesing
    sieve();
    sieveDivisor();

    for (int i = 1; i < LIM; i++)
        pre_sum[i] = pre_sum[i-1] + (isPrime[divisors[i]]);
    int t, l, r;



    std::cin >> t;
    while (std::cin >> l >> r) {
        std::cout << pre_sum[r] - pre_sum[l-1] << "\n";
    }
    return 0;
}