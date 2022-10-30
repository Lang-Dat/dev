/**
 *	author: Lang Dat
 *	create: 14.10.2022 41.01.20
 *  This implement is similar to lcs
**/
#include <iostream>
using namespace std;

int longestPalindromeSubseq(string s) {
    int si = s.size();
    int dp[si][si]; // the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string
    for (int i = si - 1; i >= 0; i--) {
        dp[i][i] = 1;
        db(i, i, dp[i][i])

        for (int j = i + 1; j < si; j++) {
            if (s[i] == s[j] && i == j - 1) {
                dp[i][j] = 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2; // i is left index so plus i by 1
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][si-1];
}
int main()
{

    string str = "bbbab";
    std::cout << longestPalindromeSubseq(str);
    return 0;
}