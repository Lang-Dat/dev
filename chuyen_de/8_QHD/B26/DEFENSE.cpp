/**
 *	author: Lang Dat
 *	create: 29-10-2022 37:07:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e3;
int h[LIM], dp[LIM];
int n;

int LIS() {
    // this problem is to find the longeset increaing subsequence 
    int best = 1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }
    return best;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEFENSE.INP", "r", stdin);
    freopen("./DEFENSE.OUT", "w", stdout);

    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        //int h[n];
        for (int i = 0; i < n; i++) {
            std::cin >> h[i];
        }
        std::cout << LIS() << "\n";
    }

    return 0;
}