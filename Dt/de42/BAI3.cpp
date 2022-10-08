#pragma GCC optimize("O2")
#include <iostream>

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

    int n, l = 0, r = -1, best = 0, curr = 0, i;
    std::cin >> n;
    short nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    if (isPrime(nums[0])) curr++;
    for (i = 1; i < n; i++) {
        if (nums[i] >= nums[i - 1] && isPrime(nums[i])) curr++;
        else {
            if (curr > best) {
                r = i;
                l = r - curr;
                best = curr;
            }
            curr = 0;
            if (isPrime(nums[i]))
                curr++;
        }
    }
    if (curr > best) {
        r = i;
        l = r - curr;
        best = curr;
    }
    std::cout << l + 1 << " " << best;
    // for (int i = l; i < r; i++)
    //     std::cout << nums[i] << " ";
    return 0;
}