/**
 *	author : Lăng Trọng Đạt
 *	creater: 03-02-2023 19:37:25
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

static const int LIM = 1e5 + 5;
static int dp[LIM];

int lengthOfLIS(string &str, int n) {
    if (n == 1 or (str[1] == '0' and n == 2)) return 0;
    // int best = 0;
    // for (int i = 0; i < n; i++) {
    //     dp[i] = 1;
    //     for (int j = 0; j < i; j++)
    //         if (str[i] >= str[j])
    //             dp[i] = max(dp[i], dp[j] + 1);
    //     best = max(best, dp[i]);
    // }
    
    // return best;
    static const int INF = INT32_MAX;
    std::vector<int> dp(n+2, INF); // dp[i]: phần tử nhỏ nhất mà tại đó một dãy con độ dài i kết thúc
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = std::upper_bound(dp.begin(), dp.end(), (str[i] - '0')) - dp.begin();
        if (dp[j-1] <= (str[i] - '0') && (str[i] - '0') <= dp[j])
            dp[j] = (str[i] - '0');
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i+1] == INF) return i;
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SODD.INP", "r", stdin);
    freopen("./SODD.OUT", "w", stdout);

    
    string str;
    while (std::cin >> str) {
        std::cout << str.size() - lengthOfLIS(str, str.size()) << "\n";
        // db(str.size(), lengthOfLIS(str, str.size()))
    }
    return 0;       
}       