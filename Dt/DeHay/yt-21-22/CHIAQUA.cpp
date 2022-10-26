/**
 *	author: Lang Dat
 *	create: 15.10.2022 52.26.15
**/
#include <iostream>
#include <algorithm>
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
ull numOfDivisor(ull n) {
    std::unordered_map<ull, ull> freq_prime = phanTichN(n);
        ull sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHIAQUA.INP", "r", stdin);
    freopen("./CHIAQUA.OUT", "w", stdout);

    ull a, b;
    std::cin >> a >> b;
    ull ucln = __gcd(a, b);
    std::cout << numOfDivisor(ucln);
    return 0;
}