// https://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <vector>

#define ull unsigned long long

int perfect_num[] = {6, 28, 496, 8128, 33550336};
// help funcion
void decresingN(ull &n, ull i, std::unordered_map<ull, ull> &freq_prime) {
    ull tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0) {
        freq_prime[i] += tmp;
    }
}
// Phân tích n ra thừa số nguyên tố và trả về umpii
std::unordered_map<ull, ull> phanTichN(ull n, std::unordered_map<ull, ull> freq_prime = {}) {
    decresingN(n, 2, freq_prime);
    decresingN(n, 3, freq_prime);
    for (ull i = 5; i * i <= n; i += 6) {
        decresingN(n, i, freq_prime);
        decresingN(n, i+2, freq_prime);
    }
    if (n > 1) freq_prime[n] += 1;
    return freq_prime;
}
ull numOfDivisor(ull n) {
    std::unordered_map<ull, ull> freq_prime = phanTichN(n);
        ull sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}
ull sumOfFactor(ull n) {
    std::unordered_map<ull, ull> freq_prime = phanTichN(n);
    double sum = 1;
    for (const auto &p : freq_prime) {
        // fix std::pow'bug by + 0.1
        sum *= ((ull)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (double)(p.first - 1); 
    }
    return sum;
}
ull tongUoc(ull n, ull sum = 0) {
    // bruce force
    for (ull i = 1; i * i<= n; i++)
        // if (n % i == 0 && i * i != n) sum += i + n / i;
        // else if (n % i == 0 && i * i == n) sum += i;
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;
        }
    return sum;
}
ull tongChuSo(ull n, ull sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isPrime_(ull n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ull i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
inline bool isPerfectSQ(ull n) {
    return (ull)std::sqrt(n) * (ull)std::sqrt(n) == n;
}
ull v_to_ull(std::vector<ull> number) {
    // convert vector contain single digit to ulleger
    ull num = 0;
    for (ull i : number) {
        num = num * 10 + i;
    }
    return num;
}
class KMP {
    const std::string &pattern;
    ull m;
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