#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

void solve(int n) {
    int best = 0;
    for (int i = 2; i * i <= n; i++) 
        while(n % i == 0) {
            best = std::max(best, i);
            n /= i;
        }
    std::cout << std::max(best, n) << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int T, n;
    std::cin >> T;
    while(std::cin >> n)
        solve(n);

    return 0;
}