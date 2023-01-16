#include <bits/stdc++.h>


const int MAX = 1e6;
const long long SUM_PRIMES = 37550402023;

bool isPrime_(uint64_t n) {
    // TC: O(sqrt(n))
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

static const int LIM_SIEVE = 1e6 + 5;
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

static const int LIM = 1e6 + 5;

int tong_uoc[LIM];
int so_uoc[LIM]; // so_uoc[i]: number of divisor of i

void sieveDivisor() {
    // Time complexity: O(nLog2(n)) (n is LIM)
    for (int i = 1; i < LIM; i++)
        for (int j = i; j < LIM; j += i)
            so_uoc[j]++;
}
void tinh_tong_uoc() {
    for (int i = 1; i < LIM; i++) {
        for (int j = 1; j * i < LIM; j++)
            tong_uoc[i*j] += i;
    }
}
