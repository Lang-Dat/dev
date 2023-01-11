/**
 *	author: Lang Dat
 *	create: 04-11-2022 15:24:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

std::vector<pair<char, pair<char, char>>> truy_vet;
class Solution {
public:
    static const int LIM = 505;
    int dp[LIM][LIM];
    int solve(string &s1, string &s2, int n, int m) {
        if (n == 0 || m == 0) return max(n, m);
        else if (dp[n][m] != 0) return dp[n][m];
        else if (s1[n-1] == s2[m-1])
            return dp[n-1][m-1] = solve(s1, s2, n - 1, m - 1);
        int xoa = solve(s1, s2, n-1, m);
        int them = solve(s1, s2, n, m-1);
        int thay_the = solve(s1, s2, n-1, m-1);
        int minn = min(xoa, min(thay_the, them));
        if (xoa == minn) truy_vet.push_back({'D', make_pair(n - '0', '-1')});
        else if (thay_the == minn) truy_vet.push_back({'R', make_pair(n - '0', s2)});
        else if (them == minn) truy_vet.push_back({'I', make_pair(n - '0', '-1')});
        return minn + 1;
    }
    // 60 ms
    // Time: O(n^2)  beats 22.44 %
    // Space: O(n^2) beats 88.66
    int minDistance(string &word1, string &word2) {
        return solve(word1, word2, word1.size(), word2.size());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./changest.INP", "r", stdin);
    // freopen("./changest.OUT", "w", stdout);

    string s1, s2;
    std::cin >> s1 >> s2;
    Solution ob;
    std::cout << ob.minDistance(s1, s2) << "";
   
    return 0;
}