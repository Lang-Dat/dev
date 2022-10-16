/**
 *	author: Lang Dat
 *	create: 14.10.2022 47.50.19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string &s) {
    int si = s.size();
    int dp[si][si]; // the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string
    for (int i = si - 1; i >= 0; i--) {
        dp[i][i] = 1;

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

bool is_palindrome(string &str) {
    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

int longestPalindrome(string &s) {
    int best = 0, n = s.size();
    string subs;

    for (int l = 0; l < n; l++) {
        subs = s.substr(l);
        for (;subs.size() > best; subs.pop_back())
            if (is_palindrome(subs)) 
                best = subs.size();
    }
    return best;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUBSTR.INP", "r", stdin);
    freopen("./SUBSTR.OUT", "w", stdout);

    string str;
    std::cin >> str;

    std::cout << longestPalindrome(str) << "\n" << longestPalindromeSubseq(str);
    return 0;
}