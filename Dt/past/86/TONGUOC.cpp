#include <iostream>
#include <algorithm>

int64_t tong_uoc(int64_t n) {
    int64_t sum = 0;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n)
                sum +=  n / i;
        }
    }

    return sum;
}

int main() {
    freopen("TONGUOC.INP", "r", stdin);
    freopen("TONGUOC.OUT", "w", stdout);

    int64_t a, b;
    std::cin >> a >> b;

    if (b % 3 == 0) {
        std::cout << tong_uoc(std::__gcd(a, b / 3));
    } else {
        std::cout << 0;
    }

}
