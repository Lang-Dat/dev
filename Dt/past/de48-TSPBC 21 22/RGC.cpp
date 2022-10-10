#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> freq_prime;

void decresingN(int &n, int i) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0)
        freq_prime[i] += tmp;
}

void soUoc(int &n) {
    decresingN(n, 2);
    decresingN(n, 3);
    for (int i = 5; i * i <= n; i += 6) {
        decresingN(n, i);
        decresingN(n, i+2);
    }
    if (n > 1) freq_prime[n]++;
    // Lay can voi phan duoi can
    int x = 1, y = 1;
    for (auto &p : freq_prime) {
        x *= (int)(std::pow(p.first, p.second / 2) + .1);
        p.second %= 2;
    }
    for (auto &p : freq_prime) {
        if (p.second != 0) y *= p.first;
    }
    std::cout << x << " " << y << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./RGC.INP", "r", stdin);
    freopen("./RGC.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        freq_prime.clear();
        soUoc(tmp);
    }
    return 0;
}