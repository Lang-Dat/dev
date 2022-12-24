/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 55:04:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


static const int LIM = 6*1e5 + 5;
int prime_freq[LIM];
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

int decre(int &n, int p) {
    int count = 0;
    while (n % p == 0) {
        count++;
        n /= p;
    }
    return count;
}
void phan_tich(int start, int end, int sign) {
    for (int i = start; i <= end; i++) {
        int tmp = i;
        for (int j = 2; j * j <= i; j++)
            prime_freq[j] += sign * decre(tmp, j);

        if (tmp > 1) 
            prime_freq[tmp] += sign;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CPRDIV.INP", "r", stdin);
    freopen("./CPRDIV.OUT", "w", stdout);
    #endif

    sieve(LIM);

    int n, m, count = 0;
    std::cin >> n >> m;

    phan_tich(m + 1, n, 1);
    phan_tich(2, n - m, -1);

    for (int i : prime_freq)
        count += i > 0;

    std::cout << count << "";

    return 0;
}