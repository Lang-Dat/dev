/**
 *	author: Lang Dat
 *	create: 23-10-2022 39:06:10
 *	[26-10-2022 43:49:14] Bug hàm sum khi chia hai số rất lớn thì bị cc gì đó nên phải cho về double mới sửa đc
 *                          lỗi làm tròn số
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
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
    double sum = 1;
    for (const auto &p : freq_prime) {
        sum *= ((ull)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (double)(p.first - 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TongUoc.INP", "r", stdin);
    freopen("./TongUoc.OUT", "w", stdout);

    ull a, b;
    std::cin >> a >> b;
    if (b % 3 != 0) {
        std::cout << 0;
        return 0;
    }

    ull ucln = __gcd(a, b / 3);   
    std::cout << sumOfFactor(ucln);
    return 0;
}