/**
 *	author: Lang Dat
 *	create: 18-11-2022 12:38:20
**/
#include <iostream>
using namespace std;

static const int LIM = 40*500000 + 5;
unsigned char dp[40][LIM];
int nums[40];
int n, target, k, ans = 0;

bool solve(int pos = 0, int curr = 0) {
    db(pos, curr)
    if (pos == k) return solve(pos + 1, curr);
    if (curr > target) return false;
    if ((pos >= n)) {
        if (curr == target) {
            ans++;
            return true;
        }
    } else if (dp[pos][curr] == 1) {
        ans++;
        return true;
    } else if (dp[pos][curr] == 0) {
        dp[pos][curr] = (solve(pos + 1, curr + nums[pos]) ||
                            solve(pos + 1, curr)) ? 1 : -1;
        if (dp[pos][curr] == 1) {
            ans++;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    // freopen("./GAME.INP", "r", stdin);
    // freopen("./GAME.OUT", "w", stdout);
    #endif

    std::cin >> n >> target >> k;
    k--;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    target -= nums[k];
    db(n, target, k)
    solve();
    std::cout << ans << "";
    return 0;
}