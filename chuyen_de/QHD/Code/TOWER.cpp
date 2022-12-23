/**
 *	author: Lang Dat
 *	create: 16-11-2022 40:28:21
**/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


int Tower(int *R, int *H, int n) {
    // TC: O(N*RMax)
    // SC: O(RMax)
    int best = 0;
    int RMax = *max_element(R, R + n);
    vector<int> dp(RMax + 1, 0);    // dp[i]: là chiều cao lớn nhất của 
                                    // tòa tháp xếp dược với i là đường kính hình trụ trên cùng
    for (int i = 0; i < n; i++) {
        for (int j = R[i]; j <= RMax; j++)
            dp[R[i]] = max(dp[R[i]], H[i] + dp[j]);
        best = max(best, dp[R[i]]);
    }

    return best;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TOWER.INP", "r", stdin);
    freopen("./TOWER.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    int R[n], H[n];
    for (int i = 0; i < n; i++) {
        std::cin >> R[i] >> H[i];
    }
    
    cout << Tower(R, H, n);
    return 0;
}