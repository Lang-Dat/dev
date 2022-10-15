/**
 *	author: Lang Dat
 *	create: 14.10.2022 33.31.19
 *	[15.10.2022 58.47.14] Bug 1: Lưu giá trị lung tung nên cho vào mảng dp là đúng liền
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ull unsigned long long

const int LIM = 30005;
int nums[LIM];
int dp[LIM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("./JUMP.INP", "r", stdin);
    freopen("./JUMP.OUT", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    dp[1] = std::abs(nums[0] - nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + std::abs(nums[i] - nums[i-1]), 
                    dp[i-2] + 3*std::abs(nums[i] - nums[i-2]));
    }
    cout << dp[n-1];
    return 0;
}