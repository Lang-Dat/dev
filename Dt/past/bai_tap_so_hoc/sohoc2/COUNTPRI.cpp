/**
 *	author: Lăng Trọng Đạt
 *	create: 11-12-2022 03:32:10
**/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

static const int LIM = 1e6 + 6;
// static const int LIM = 40;
int pre_sum[LIM]; // pre_sum[i]: số snt bé hơn i
// bool isPrime[LIM];
uint64_t sieve_mark[LIM / 64 + 11];
uint64_t ONES[64];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int &bit) { return ((sieve_mark[bit / 64] & ONES[bit & 63]) == 0) and bit & 1; }

void sieve() {
    for (int i = 0; i < 64; i++) ONES[i] = 1ULL << i;

    for (int i = 3; i * i <= LIM; i += 2) {
        if (is_prime(i)) {
            for (int j = i * i; j < LIM; j += i * 2)
                mark(j);
        }
    }
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./COUNTPRI.INP", "r", stdin);
    // freopen("../../../chuyen_de/1_SOHOC_B1234/sohoc2/COUNTPRI/test4/COUNTPRI.INP", "r", stdin);
    freopen("./COUNTPRI.OUT", "w", stdout);
    #endif

    sieve();

    // build pre_sum;
    pre_sum[2] = 1;
    for (int i = 3; i < LIM; i++)
        pre_sum[i] = pre_sum[i-1] + (int)is_prime(i);

    int n, l, r;
    std::cin >> n;
    while (std::cin >> l >> r) {
        std::cout << pre_sum[r] - pre_sum[l-1] << "\n";
    }

    return 0;
}