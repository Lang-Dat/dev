// https://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <vector>

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
ull numOfDivisor(ull n) {
    std::unordered_map<int, int> freq_prime = phanTichN(n);
        int sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}
int tongUoc(int n, int sum = 0) {
    // bruce force
    for (int i = 1; i <= n; i++)
        // if (n % i == 0 && i * i != n) sum += i + n / i;
        // else if (n % i == 0 && i * i == n) sum += i;
        if (n % i == 0) {
            sum += i;
            // if (i * i != n) sum += n / i;
        }
    return sum;
}
int tongChuSo(int n, int sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
inline bool isPerfectSQ(int n) {
    return (int)std::sqrt(n) * (int)std::sqrt(n) == n;
}
int v_to_int(std::vector<int> number) {
    // convert vector contain single digit to integer
    int num = 0;
    for (int i : number) {
        num = num * 10 + i;
    }
    return num;
}
int main() {
    // freopen("test.inp", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("test.inp", "r", stdin);
    int count = 10000;
    // for (int i = 532664; i < 532664 + count; i += 7)
    //     std::cout << i << " ";
    // for (int i = 532664; i < 532664 + count; i += 3)
    //     std::cout << i << " ";
    int n;
    Timer time;
    // log(sumOfFactor(n), tongUoc(n))
    for (int i = 0; i < 2 * count; i++)
    {
        std::cin >> n;
        // sumOfFactor(n);
        tongUoc(n);
        // if (sumOfFactor(n) != tongUoc(n))
        //     std::cout << n << " ";
    }
    logm("Done in\n")
}