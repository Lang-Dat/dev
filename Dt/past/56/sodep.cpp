/**
 *	author : Lăng Trọng Đạt
 *	creater: 14-01-2023 19:29:59
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM_SIEVE = 1e6 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM_SIEVE / 64 + 11];
int64_t pre_count[LIM_SIEVE];

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
    freopen("./sodep.INP", "r", stdin);
    freopen("./sodep.OUT", "w", stdout);
    #endif

    sieve(LIM_SIEVE);

    for (int i = 2; i < LIM_SIEVE; i++) {
        pre_count[i] = pre_count[i-1] + (i & 1 and is_prime(i) and is_prime((i + 1) / 2));
    }    
    int q, l, r;
    std::cin >> q;
    while (std::cin >> l >> r) {
        std::cout << pre_count[r] - pre_count[l - 1] << "\n";
    }
    
    return 0;
}