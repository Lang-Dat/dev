/**
 *	author: Lang Dat
 *	create: 02-11-2022 13:46:06
**/
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

#define ull unsigned long long

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
ull sumOfFactor(ull n) {
    std::unordered_map<ull, ull> freq_prime = phanTichN(n);
    int sum = 1;
    for (const auto &p : freq_prime) {
        // fix std::pow'bug by + 0.1
        sum *= ((ull)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (double)(p.first - 1); 
        // sum *= (std::pow(p.first, p.second + 1) - 1) / (p.first - 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./UOC.INP", "r", stdin);
    freopen("./UOC.OUT", "w", stdout);

    int n, tmp, sum = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        sum += sumOfFactor(tmp);
    }     

    std::cout << sum << "";
    return 0;
}