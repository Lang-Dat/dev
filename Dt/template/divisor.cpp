#include <bits/stdc++.h>


// help funcion
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
    return sum;
}
uint64_t sumOfFactor(uint64_t n) {
    std::unordered_map<uint64_t, uint64_t> freq_prime = phanTichN(n);
    double sum = 1;
    for (const auto &p : freq_prime) {
        // fix std::pow'bug by + 0.1
        sum *= ((uint64_t)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (double)(p.first - 1); 
    }
    return sum;
}

int chia(int64_t &n, int64_t tmp) {
    int count = 0;
    while (n % tmp == 0) {
        n /= tmp;
        count++;
    }
    return count;
}

int64_t tong_uoc(int64_t n) {
    int ans = 1;
    ans *= ((int64_t)(std::pow(2, chia(n, 2) + 1) + 0.1) - 1); 
    ans *= ((int64_t)(std::pow(3, chia(n, 3) + 1) + 0.1) - 1) / 2; 
    for (int i = 5; i * i <= n; i += 6) {
        ans *= ((int64_t)(std::pow(i, chia(n, i) + 1) + 0.1) - 1) / (double)(i - 1); 
        ans *= ((int64_t)(std::pow(i + 2, chia(n, i + 2) + 1) + 0.1) - 1) / (double)(i + 2 - 1); 
    }
    if (n > 1)
        ans *= (n*n - 1) / (double)(n - 1); 

    return ans;
}

int64_t so_uoc(int64_t n) {
    int ans = 1;
    ans *= chia(n, 2) + 1; 
    ans *= chia(n, 3) + 1; 
    for (int i = 5; i * i <= n; i += 6) {
        ans *= chia(n, i) + 1; 
        ans *= chia(n, i + 2) + 1; 
    }
    if (n > 1)
        ans *= 2; 

    return ans;
}
