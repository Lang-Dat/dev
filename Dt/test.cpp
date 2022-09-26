#include <math.h>
#include <iostream>

bool isPrime(int n) {
    if (n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main() {
    freopen("./test.out", "r", stdin);
    int n;
    while (std::cin >> n)
    {
        if (!isPrime(n)) {
            log(n);
        }
    }
    
}