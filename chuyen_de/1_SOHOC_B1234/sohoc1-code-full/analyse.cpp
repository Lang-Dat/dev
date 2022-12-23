/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 05:11:16
**/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static const int LIM = 1e3 + 5;
int freq[LIM];
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

void phanTich(int n, int &max_prime) {
    while (n % 2 == 0) {
        freq[2]++;
        n /= 2;
    } 
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime(i))
            while (n % i == 0) {
                n /= i;
                freq[i]++;
                max_prime = max(max_prime, i);
            }
    }
    if (n > 1) {
        freq[n]++;
        max_prime = max(max_prime, n);
    }
}

void solve(int n) {
    int max_prime = 2;
    memset(freq, 0, sizeof(freq));
    for (int i = 1; i <= n; i++)
        phanTich(i, max_prime);
    std::cout << freq[2] << " ";
    for (int i = 3; i <= max_prime; i += 2)
        if (is_prime(i))
            std::cout << freq[i] << " ";
    std::cout << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./analyse.INP", "r", stdin);
    freopen("./analyse.OUT", "w", stdout);
    #endif

    sieve(1e3 + 2);
    int n;
    while (std::cin >> n) {
        solve(n);
    }   

    return 0;
}