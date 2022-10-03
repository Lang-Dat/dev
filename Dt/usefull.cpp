#include <math.h>

int tongChuSo(int n, int sum = 0) {
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}