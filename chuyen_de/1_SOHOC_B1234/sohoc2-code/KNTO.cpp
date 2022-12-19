/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 56:06:19
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
std::unordered_map<uint64_t, uint64_t> phanTichN(uint64_t n, std::unordered_map<uint64_t, uint64_t> freq_prime = {}) {
    decresingN(n, 2, freq_prime);
    decresingN(n, 3, freq_prime);
    for (uint64_t i = 5; i * i <= n; i += 6) {
        decresingN(n, i, freq_prime);
        decresingN(n, i+2, freq_prime);
    }
    if (n > 1) freq_prime[n] += 1;
    return freq_prime;
}
uint64_t numOfDivisor(uint64_t n) {
    std::unordered_map<uint64_t, uint64_t> freq_prime = phanTichN(n);
        uint64_t sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum - freq_prime.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./KNTO.INP", "r", stdin);
    freopen("./KNTO.OUT", "w", stdout);
    #endif

    uint64_t n;
    std::cin >> n;
    std::cout << numOfDivisor(n) << "";   

    return 0;
}