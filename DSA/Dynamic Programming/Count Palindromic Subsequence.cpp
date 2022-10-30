#include <iostream>
#include <cstring>

#define ull unsigned long long
static const int LIM = 1005;
static const int MOD = 1e9 + 7;
ull dp[LIM][LIM];

std::string str;

ull countPS(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1)
        return dp[l][r]%MOD;
    
    if (l == r)
        return dp[l][r] = 1;
    else if (str[l] == str[r])
        return dp[l][r] = (1 + countPS(l + 1, r)%MOD + 
                               countPS(l, r - 1)%MOD)% MOD;
    else
        return dp[l][r] = (countPS(l + 1, r)%MOD +
                          countPS(l, r - 1)%MOD -
                          countPS(l + 1, r - 1)%MOD) % MOD;
}

int main() {
    std::memset(dp, -1, sizeof dp);
    str = "aab";
    std::cout << countPS(0, str.size() - 1) % MOD << "\n";
}