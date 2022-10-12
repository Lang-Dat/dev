/**
 *	author: Lang Dat
 *	create: 12.10.2022 43.25.09
**/
#include <bits/stdc++.h>
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
int numOfDivisor(int n) {
    std::unordered_map<int, int> freq_prime = phanTichN(n);
        int sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CACHCHIA.INP", "r", stdin);
    freopen("./CACHCHIA.OUT", "w", stdout);

    int n;
    while (std::cin >> n) {
        std::cout << numOfDivisor(n) << "\n";
    }

    return 0;
}