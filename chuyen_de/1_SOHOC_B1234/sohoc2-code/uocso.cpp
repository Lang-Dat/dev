/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 43:38:19
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void decresingN(uint64_t &n, uint64_t i, std::unordered_map<uint64_t, uint64_t> &freq_prime) {
    uint64_t tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0) {
        freq_prime[i] += tmp;
    }
}
// Phân tích n ra thừa số nguyên tố và trả về umpii
void phanTichN(uint64_t n, std::unordered_map<uint64_t, uint64_t> &freq_prime) {
    decresingN(n, 2, freq_prime);
    decresingN(n, 3, freq_prime);
    for (uint64_t i = 5; i * i <= n; i += 6) {
        decresingN(n, i, freq_prime);
        decresingN(n, i+2, freq_prime);
    }
    if (n > 1) freq_prime[n] += 1;
}
uint64_t numOfDivisor(uint64_t n, std::unordered_map<uint64_t, uint64_t> freq_prime) {
    phanTichN(n, freq_prime);
        uint64_t sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./uocso.INP", "r", stdin);
    freopen("./uocso.OUT", "w", stdout);
    #endif

    int a, b, t;
    std::cin >> t;
    while (std::cin >> a >> b) {
        std::unordered_map<uint64_t, uint64_t> freq_prime;
        phanTichN(a, freq_prime);
        std::cout << numOfDivisor(b, freq_prime) << "\n";
    }

    return 0;
}