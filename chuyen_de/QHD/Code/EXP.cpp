// Bai 5 / trang 182
/**
 *	author: Lang Dat
 *	create: 14-11-2022 16:58:14
**/
#include <iostream>
using namespace std;

static const int LIM = 50 * 500 + 5;
int dp[500 + 5][LIM];
int nums[500 + 5];
int target, n, sum;

bool dfs(int pos = 0, int curr = 0) {
    if (pos == n) return 2*curr - sum == target;
    else if (dp[pos][curr] != 0) return dp[pos][curr] == 1;
    else if (dfs(pos + 1, curr + nums[pos]) || dfs(pos + 1, curr)) {
        dp[pos][curr] = 1;
        return true;
    } else {
        dp[pos][curr] = -1;
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./EXP.INP", "r", stdin);
    freopen("./EXP.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    std::cin >> target;

    if (dfs())
        std::cout << "YES";
    else 
        std::cout << "NO";

    return 0;
}