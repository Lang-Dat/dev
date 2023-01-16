/**
 *	author : Lăng Trọng Đạt
 *	creater: 14-01-2023 20:09:22
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

std::unordered_set<string> words;
int n, ans = 0;
std::vector<int64_t> dp(105, -1);
string str;

int64_t solve(int start = 0) {
    if (start == str.size()) {
        return 1;
    } else if (dp[start] != -1) {
        return dp[start];
    }
        
    string tmp = "";
    dp[start] = 0;
    for (int i = start; i < str.size(); i++) {
        tmp += str[i];
        if (words.count(tmp)) {
            dp[start] += solve(i + 1);
        }
    }
    return dp[start];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./vanban.INP", "r", stdin);
    freopen("./vanban.OUT", "w", stdout);
    #endif

    std::cin >> n;
        
    for (int i = 0;i < n; i++) {
        std::cin >> str;
        words.insert(str);
    }
    std::cin >> str;
    std::cout << solve(0) << "";
    return 0;
}