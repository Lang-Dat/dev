/**
 *	author: Lăng Trọng Đạt
 *	create: 26-12-2022 52:19:22
**/
#include <iostream>
#include <algorithm>
using namespace std;


static const int LIM = 1e6 + 5;
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

int tong_chu_so(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DOCAO.INP", "r", stdin);
    freopen("./DOCAO.OUT", "w", stdout);
    #endif

    sieve(LIM);

    int n, h;
    std::cin >> n >> h;   

    int count = (h == 2);
    if (count)
        std::cout << 2 << "\n";

    for (int i = 3; i <= n; i += 2) {
        if (is_prime(i) and tong_chu_so(i) == h) {
            std::cout << i << "\n";
            count++;
        }
    }

    std::cout << count << "";
    
    return 0;
}