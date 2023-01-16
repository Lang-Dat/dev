/**
 *	author: Lăng Trọng Đạt
 *	create: 22-12-2022 14:26:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
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
    freopen("./BOBASO.INP", "r", stdin);
    freopen("./BOBASO.OUT", "w", stdout);
    #endif

    sieve(LIM);

    int k;
    std::cin >> k;

    int count = 0;
    for (int i = 2; 3*i <= k; i++) {
        if (is_prime(i))
            for (int j = i; 2 * j + i <= k; j++) 
                if (is_prime(j) and is_prime(k - i - j)) {
                    count++;
                }
    }

    std::cout << count << "";
    return 0;
}