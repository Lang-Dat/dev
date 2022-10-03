#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 9 * 9 * 7;
std::vector<bool> isPrime(LIM, true);

int sumOfDigit(int n) {
    int sum = 0;
    while(n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

void sieve() {
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i < LIM; i++)
        if (isPrime[i])
            for (int j = i * i; j < LIM; j += i)
                isPrime[j] = false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BEAUTY.INP", "r", stdin);
    freopen("./BEAUTY.OUT", "w", stdout);

    int n;
    sieve();

    while (std::cin >> n) {
        for (int i = 3; i < n; i++)   
            if (isPrime[sumOfDigit(i)])
                std::cout << i << " ";
        std::cout << "\n";
    }
    return 0;
}