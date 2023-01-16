/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 28:54:19
**/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void decresingN(int &n, int i, std::unordered_map<int, int> &freq_prime) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0) {
        freq_prime[i] += tmp;
    }
}
// Phân tích n ra thừa số nguyên tố và trả về umpii
std::unordered_map<int, int> phanTichN(int n, std::unordered_map<int, int> freq_prime = {}) {
    decresingN(n, 2, freq_prime);
    decresingN(n, 3, freq_prime);
    for (int i = 5; i * i <= n; i += 6) {
        decresingN(n, i, freq_prime);
        decresingN(n, i+2, freq_prime);
    }
    if (n > 1) freq_prime[n] += 1;
    return freq_prime;
}
int numOfDivisor(int n) {
    std::unordered_map<int, int> freq_prime = phanTichN(n);
        int sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}
static const int LIM = 1e6 + 5;
int ONES[64]; // 1 << i
int sieve_mark[LIM / 64 + 11];

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

inline bool isPerfectSQ(int n) {
    return (int)std::sqrt(n) * (int)std::sqrt(n) == n and n != 1;
}
int so_uoc(int n) {
    int ans = 1;
    for (int i = 2; i * i * i < n; i++) {
        if (is_prime(i)) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            ans *= (count + 1);
        }
    }

    if (is_prime(n)) ans *= 2;
    else if (isPerfectSQ(n)) ans *= 3;
    else if (ans != 1) ans *= 4;
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    // freopen("./counting factor.INP", "r", stdin);
    // freopen("./counting factor.OUT", "w", stdout);
    #endif

    sieve(1e6);
    db(so_uoc(6), numOfDivisor(6));
    // for (int i = 1; i <= 1000; i++)
        // if (so_uoc(i) != numOfDivisor(i))
            // db(i)

    return 0;
}