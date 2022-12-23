#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

// int solve(int n) {
//     int best = 0;
//     for (int i = 2; i * i <= n; i++) 
//         while(n % i == 0) {
//             best = std::max(best, i);
//             n /= i;
//         }
//     return std::max(best, n);
// }

int efficient(int n) {
    int best = 0;
    while(n % 2 == 0) {
        n /= 2;
        best = 2;
    }
    while(n % 3 == 0) {
        n /= 3;
        best = 3;
    }
    for (int i = 5; i * i <= n; i += 6) {
        while(n % i == 0) {
            best = i;
            n /= i;
        }
        while(n % (i + 2) == 0) {
            best = (i + 2);
            n /= (i + 2);
        }
    }
    return std::max(best, n);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int T, n;
    std::cin >> T;
    // while(std::cin >> n)
    for (int i = 0; i < T; i++) {
        std::cin >> n;
       std::cout << efficient(n) << "\n";
    }
    return 0;
}