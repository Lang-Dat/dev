#include <iostream>

bool is_prime(int n) {
    if (n == 3 or n == 2) return true;
    if (n < 2 or n % 3 == 0 or n % 2 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0)
                return false;
    }

    return true;
}
int main() {
    freopen("PrimeLast.INP", "r", stdin);
    freopen("PrimeLast.OUT", "w", stdout);

    int n, tmp, sum = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (is_prime(tmp))
            sum += tmp % 10;
    }

    std::cout << sum;
}
