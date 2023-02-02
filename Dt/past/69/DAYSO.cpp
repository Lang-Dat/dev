/**
 *	author : Lăng Trọng Đạt
 *	creater: 30-01-2023 14:13:11
**/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

static const int LIM = 500 + 5;
static int nums[LIM];
vector<vector<int>> dp;
int n, total = 0;
std::vector<int> ans;
bitset<2*LIM*LIM> s[LIM];

bool split(int pos, int curr, int skip, int &curr_total) {
    if (pos == skip)
        return split(pos + 1, curr, skip, curr_total);
    if (dp[pos][curr] != -1)
        return dp[pos][curr];
    else if (pos == n + 1) {
        return 2*curr == curr_total; 
    } else if (2 * curr > curr_total)
        return dp[pos][curr] = false;

    return dp[pos][curr] = split(pos + 1, curr, skip, curr_total) or 
                           split(pos + 1, curr + nums[pos], skip, curr_total);
}

bool can_add(int num) {
    for (int skip = 0; skip < n; skip++) {
        int curr_total = total - nums[skip] + num;
        // temp = s[skip] | (s[skip] << num);
        // if (num == 5)
        // db(temp, num, skip, curr_total)
        if (curr_total & 1 or !(s[skip][curr_total / 2] or 
           (curr_total / 2 - num >= 0 and s[skip][curr_total / 2 - num])))
            return false;
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DAYSO.INP", "r", stdin);
    // freopen("./DAYSO/DAYSO/Test09/DAYSO.INP", "r", stdin);
    freopen("./DAYSO.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        // distict_num.insert(nums[i]);
        total += nums[i];
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                s[j][0] = 1;
            if (i != j)
                s[j] |= (s[j] << nums[i]);
        }
    }

    if (total & 1 or !s[n][total / 2]) {
        std::cout << 0 << "";
        return 0;
    }
    
    for (int i = 1; i <= total; i += 2) {
        nums[n] = i;
        if (can_add(i))
            ans.push_back(i);
    }

    std::cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i : ans)
        std::cout << i << " ";

    return 0;
}