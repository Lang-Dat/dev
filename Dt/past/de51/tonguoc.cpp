// https://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number
#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <unordered_map>

#define ull unsigned long long

// help funcion
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
int sumOfFactor(ull n) {
    std::unordered_map<int, int> freq_prime = phanTichN(n);
    ull sum = 1;
    for (const auto &p : freq_prime) {
        // fix std::pow'bug by + 0.1
        sum *= ((ull)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (ull)(p.first - 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./tonguoc.INP", "r", stdin);
    freopen("./tonguoc.OUT", "w", stdout);

    ull n;
    std::cin >> n;

    std::cout << sumOfFactor(n);
    return 0;
}