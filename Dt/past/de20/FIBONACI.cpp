#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>

std::vector<int> fibo;

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./FIBONACI.INP", "r", stdin);
    freopen("./FIBONACI.OUT", "w", stdout);

    int prev = 0, second = 1, count = 0;
    int n; std::cin >> n;
    fibo.reserve(54);
    while (second < n) {
        fibo.push_back(second);
        int tmp = second;
        second += prev;
        prev = tmp;
    }
    for (int i = fibo.size() - 1; i >= 0; i--)
        if (isPrime(fibo[i])) {
            std::cout << fibo[i];
            return 0;
        }
    return 0;
}