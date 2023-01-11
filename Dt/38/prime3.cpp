/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 40:31:19
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime_(uint64_t n) {
    // TC: O(sqrt(n))
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

static const int LIM = 1e7 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM / 64 + 11];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int bit) { return (bit != 1 and bit % 2 != 0) and (sieve_mark[bit / 64] & ONES[bit & 63]) == 0 or bit == 2; }
void sieve(int n) {
    for (int i = 0; i < 64; i++) ONES[i] = 1ULL << i; // turn bit i on

    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime(i)) {
            for (int j = i * i; j < n; j += i + i)
                mark(j);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./prime3.INP", "r", stdin);
    // freopen("./PRIME3/test08/prime3.INP", "r", stdin);
    freopen("./prime3.OUT", "w", stdout);
    #endif

    sieve(LIM);
    int64_t n;
    std::cin >> n;
    bool is_printed = false;
    for (int64_t i = 3; i * i + 4 < n; i += 2) 
        if (is_prime(i) and isPrime_(i*i + 4)) {
            std::cout << 2 << " " << i << " " << i*i + 4 << "\n";
            is_printed = true;
        }

    if (!is_printed)
        std::cout << -1 << "";

    return 0;
}