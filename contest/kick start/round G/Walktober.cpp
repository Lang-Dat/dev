/**
 *	author: Lang Dat
 *	create: 15.10.2022 36.12.19
**/
#include <bits/stdc++.h>
using namespace std;

int nums[1000][31];
void solve() {
    int M, N, id, max_, ans = 0;
    std::cin >> M >> N >> id;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> nums[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1, max_ = nums[0][i]; j < M; j++) {
            max_ = max(max_, nums[j][i]);
        }
        if (max_ > nums[i][id]) {
            ans += max_ - nums[i][id];
            // db(ans)
        }
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./in.inp", "r", stdin);
    freopen("./in.out", "w", stdout);

    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}