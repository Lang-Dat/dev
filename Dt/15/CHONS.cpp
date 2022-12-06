/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 12:19:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1001;
// static const int LIM = 5;
bool dp[LIM][LIM*100];
int nums[LIM];
int n, ans = 0, total = 0;

void recursion(int pos = 0, int curr_sum = 0) {
    if (pos > n or dp[pos][curr_sum] == true) return;
    dp[pos][curr_sum] = true;
    recursion(pos + 1, curr_sum + nums[pos]);
    recursion(pos + 1, curr_sum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CHONS.INP", "r", stdin);
    // freopen("./Test/CHONS/Test036/CHONS.INP", "r", stdin);
    freopen("./CHONS.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        total += nums[i];
    }
        
    recursion();
    for (int i = 1; i <= total; i++)
        for (int j = 0; j <= n; j++)
            if (dp[j][i]) {
                // db(i, j)
                ans++;
                break;
            }

    std::cout << ans << "";
    return 0;
}