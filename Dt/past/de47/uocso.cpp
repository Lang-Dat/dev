#pragma GCC optimize("O2")
#include <math.h>
#include <unordered_map>
#include <iostream>

#define ull unsigned long long
std::unordered_map<int, int> freq_prime;

void decresingN(ull &n, ull i) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0)
        freq_prime[i] += tmp;
}

void soUoc(ull &n) {
    decresingN(n, 2);
    decresingN(n, 3);
    for (ull i = 5; i * i <= n; i += 6) {
        decresingN(n, i);
        decresingN(n, i+2);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./uocso.INP", "r", stdin);
    freopen("./uocso.OUT", "w", stdout);

    ull t, a, b;
    std::cin >> t;
    while (std::cin >> a >> b) {
        freq_prime.clear();
        soUoc(a); soUoc(b);
        int res = 1;
        for (const auto &p : freq_prime) {
            res *= (p.second + 1);
        }
        if (a > 1 && b > 1) {
            if (a == b) res *= 3;
            else res *= 4; // (1+1)*(1+1)
        } else if (a > 1 || b > 1) {
            res *= 2;
        }
        std::cout << res << "\n";
    }
    return 0;
}