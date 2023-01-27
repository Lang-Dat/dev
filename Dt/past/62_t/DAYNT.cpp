/**
 *	author : Lăng Trọng Đạt
 *	creater: 25-01-2023 15:56:10
**/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


static const int LIM_SIEVE = 1e5 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM_SIEVE / 64 + 11];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int bit) { return (bit > 1 and bit % 2 != 0) and (sieve_mark[bit / 64] & ONES[bit & 63]) == 0 or bit == 2; }

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
    freopen("./DAYNT.INP", "r", stdin);
    freopen("./DAYNT.OUT", "w", stdout);
    #endif

    sieve(LIM_SIEVE);

    int k, tmp;
    std::set<int> primes;
    std::cin >> k;
    while (std::cin >> tmp) {
        if (is_prime(tmp) and !primes.count(tmp))
            primes.insert(tmp);
    }

    int count = 0;
    for (auto& p : primes) {
        if (++count > k) break;
        std::cout << p << " ";
    }
    return 0;
}