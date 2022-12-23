#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 1e5 + 5;
std::vector<int> nums;

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0) return false;

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NUMBER.INP", "r", stdin);
    freopen("./NUMBER.OUT", "w", stdout);

    nums.reserve(LIM);
    int tmp;
    while (std::cin >> tmp)
        nums.push_back(tmp);
        
    std::vector<bool> primes(nums.size(), false);

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (isPrime(nums[i])) primes[i] = true;
        if (primes[i] && primes[i+2]) {
            std::cout << i + 2;
            return 0;
        }
    }
    std::cout << 0;
    return 0;
}