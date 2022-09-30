#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 1e4;
int m[2][LIM], nums1[LIM], nums2[LIM];
int n;
int longestCommonSubsequence() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (nums1[i] == nums2[j]) m[!(i % 2)][j+1] = 1 + m[i % 2][j];
            else m[!(i % 2)][j+1] = std::max(m[i % 2][j+1], m[!(i % 2)][j]);
    return m[n % 2][n];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SCORE.INP", "r", stdin);
    freopen("./SCORE.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> nums1[i];
    for (int i = 0; i < n; i++) std::cin >> nums2[i];
    std::cout << longestCommonSubsequence();
    return 0;
}