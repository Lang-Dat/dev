/**
 *	author: Lang Dat
 *	create: 25-10-2022 03:22:09
**/
#include <iostream>
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
    return sum - freq_prime.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KNTO.INP", "r", stdin);
    freopen("./KNTO.OUT", "w", stdout);

    ull n;
    std::cin >> n;
    std::cout << numOfDivisor(n);
    return 0;
}