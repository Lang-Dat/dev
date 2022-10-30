/**
 *	author: Lang Dat
 *	create: 26-10-2022 23:36:17
**/
#include <iostream>
#include <cstring>
using namespace std;

#define ull unsigned long long
static const int LIM = 205;
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PAL.INP", "r", stdin);
    freopen("./PAL.OUT", "w", stdout);
    std::memset(dp, -1, sizeof dp);
    std::cin >> str;
    std::cout << countPS(0, str.size() - 1) << "";
}