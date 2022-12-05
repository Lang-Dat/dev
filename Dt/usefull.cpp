// https://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <vector>

#define uint64_t unsigned long long

static const int MAXX = 1e6;
static const int SUM_OF_PRIME = 37550402023;
int perfect_num[] = {6, 28, 496, 8128, 33550336};
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
uint64_t tongUoc(uint64_t n, uint64_t sum = 0) {
    // bruce force
    for (uint64_t i = 1; i * i<= n; i++)
        // if (n % i == 0 && i * i != n) sum += i + n / i;
        // else if (n % i == 0 && i * i == n) sum += i;
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;
        }
    return sum;
}
uint64_t tongChuSo(uint64_t n, uint64_t sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isPrime_(uint64_t n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
inline bool isPerfectSQ(uint64_t n) {
    return (uint64_t)std::sqrt(n) * (uint64_t)std::sqrt(n) == n;
}
uint64_t v_to_uint64_t(std::vector<uint64_t> number) {
    // convert vector contain single digit to uint64_teger
    uint64_t num = 0;
    for (uint64_t i : number) {
        num = num * 10 + i;
    }
    return num;
}
class KMP {
    const std::string &pattern;
    uint64_t m;
    std::vector<int> table;
public:
    KMP(const std::string &pattern)
        : pattern(pattern), table(pattern.size()), m(pattern.size()) {
        int i = 0;
        for (int j = 1; j < m; j++) {
            while (i > 0 && pattern[i] != pattern[j])
                i = table[i-1];
            if (pattern[i] == pattern[j])
                i += 1;
            table[j] = i;
        }
    }  
    std::vector<int> find_in(const std::string &haystack) {
        std::vector<int> index_of_occu;
        for (int i = 0, j = 0; j < (int)haystack.size(); j++) {
            while (i > 0 && pattern[i] != haystack[j])
                i = table[i-1];
            if (pattern[i] == haystack[j])
                i += 1;
            if (i == m) {
                index_of_occu.push_back(j + 1 - m);
                i = table[i-1];
            }
        }
        return index_of_occu;
    }
};

const int LIM = 1e6 + 6;
std::vector<bool> isPrime(LIM, true);

void sieve(int n) {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}
static const int LIM = 2*1e6 + 4;
int tong_uoc[LIM];

static const int LIM_VALUE = 1e6;
int divisors[LIM_VALUE]; // divisors[i]: number of divisor of i

void sieveDivisor() {
    // Time complexity: O(nLog2(n)) (n is LIM_VALUE)
    for (int i = 1; i < LIM_VALUE; i++)
        for (int j = i; j < LIM_VALUE; j += i)
            divisors[j]++;
}
void tinh_tong_uoc() {
    for (int i = 1; i < LIM; i++) {
        for (int j = 1; j * i < LIM; j++)
            tong_uoc[i*j] += i;
    }
}
int main() {
    for (int i = 1; i < 1e6; i++)
        if(tongUoc(i) != sumOfFactor(i))
            db(i)
}