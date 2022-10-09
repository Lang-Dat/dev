#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 1e5 + 5;
std::vector<int> isPrime(LIM, true);

void sieve() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < LIM; i++)
        if (isPrime[i])
            for (int j = i * i; j < LIM; j += i)
                isPrime[j] = false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOANCON.INP", "r", stdin);
    freopen("./DOANCON.OUT", "w", stdout);

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sieve();

    int best = 0, start, curr_length = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime[nums[i]]) {
            curr_length++;
            if (curr_length >= best) {
                best = curr_length;
                start = i - curr_length + 1;
            }
        } else {
            curr_length = 0;
        }
    }
    if (best == 0) {
        std::cout << -1;
        return 0;
    }
    std::cout << best << "\n";
    for (int i = start; i < start + best; i++)
        std::cout << nums[i] << " ";
    return 0;
}