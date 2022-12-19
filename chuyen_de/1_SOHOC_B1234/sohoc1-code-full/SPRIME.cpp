/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 15:27:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e7 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM / 64 + 11];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int &bit) { return (bit != 1 and bit % 2 != 0) and (sieve_mark[bit / 64] & ONES[bit & 63]) == 0 or bit == 2; }

void sieve(int n) {
    for (int i = 0; i < 64; i++) ONES[i] = 1ULL << i; // turn bit i on

    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime(i)) {
            for (int j = i * i; j < n; j += i + i)
                mark(j);
        }
    }
}

bool check(int n) {
    while (n > 0) {
        if (!is_prime(n)) return false;
        n /= 10;
    }
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SPRIME.INP", "r", stdin);
    freopen("./SPRIME.OUT", "w", stdout);
    #endif

    int a, b;
    std::cin >> a >> b;
    sieve(b);
    for (int i = a; i < b; i++)
        if (check(i))
            std::cout << i << "\n";
    return 0;
}