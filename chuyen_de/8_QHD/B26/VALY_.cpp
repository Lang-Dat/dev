/**
 *	author: Lang Dat
 *	create: 09-11-2022 58:49:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 105;
int dp[LIM], vet[LIM], freq[LIM];
int weights[LIM], values[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./VALY.INP", "r", stdin);
    freopen("./VALY.OUT", "w", stdout);
    #endif

    int n, w;
    std::cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        std::cin >> weights[i] >> values[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = weights[i]; j <= w; j++) {
            if (dp[j - weights[i]] + values[i] > dp[j]) {
                dp[j] = dp[j - weights[i]] + values[i];
                vet[j] = i;
            }
        }
    }
    std::cout << dp[w] << "\n";
    int j = w;
    while (dp[j-1] == dp[j])
        j--;
    while (j > 0) {
        freq[vet[j]]++;
        j = j - weights[vet[j]];
    }
    for (int i = 0; i < LIM; i++) {
        if (freq[i] != 0) {
            std::cout << i << " " << freq[i] << "\n";
        }
    }
    return 0;
}