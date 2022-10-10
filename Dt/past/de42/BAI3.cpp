#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int n, l = 0, best = 0, curr = 0, i;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    curr = isPrime(nums[0]);
    for (i = 1; i < n; i++) {
        if (nums[i] >= nums[i - 1] && isPrime(nums[i])) {
            curr++;
            if (curr > best) {
                l = i - curr + 1;
                best = curr;
            }
        }
        else {
            curr = isPrime(nums[i]);
        }
    }
    std::cout << l + 1 << " " << best;
    return 0;
}