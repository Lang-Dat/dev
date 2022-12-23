/**
 *	author: Lang Dat
 *	create: 23-10-2022 10:06:15
**/
#include <iostream>
#include <cmath>
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
    freopen("./KhongHoanHao.INP", "r", stdin);
    freopen("./KhongHoanHao.OUT", "w", stdout);

    int a, b, ans = 0;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        ans += (sumOfFactor(i) - i > i);
    }
    std::cout << ans;
    return 0;
}