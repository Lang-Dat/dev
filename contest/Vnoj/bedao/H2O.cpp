/**
 *	author: Lang Dat
 *	create: 16-10-2022 35:16:20
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

const int LIM = 1e6 + 6;
ull dp[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n, total_W = 0, W, X, prev = 1, Q, L, R;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> X >> W;
        for (;prev <= X; prev++) {
            dp[prev] = dp[prev - 1] + total_W;
        }
        total_W += W;
    }
    for (;prev <= LIM; prev++) {
        dp[prev] = dp[prev - 1] + total_W;
    }
    std::cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> L >> R;
        std::cout << dp[R] - dp[L - 1] << "\n";
    }
    
    return 0;
}