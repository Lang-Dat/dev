#include <iostream>
#include <algorithm>
static const int LIM = 1e5 + 5;
int nums[LIM][3], dp[LIM][3];

int main() {
        freopen("Vacation.inp", "r", stdin);
        freopen("Vacation.out", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            dp[i][j] = nums[i][j] + std::max(dp[i - 1][(j + 3 - 1) % 3], dp[i - 1][(j + 1) % 3]);
    }
    int ind = std::max_element(dp[n], dp[n] + 3) - dp[n];
    std::cout << dp[n][ind] << "\n";
    std::string ans = "";
    for (int i = n; i > 0; i--) {
        if (dp[i][ind] == nums[i][ind] + dp[i - 1][(ind + 1) % 3]) {
            ind = (ind + 1) % 3;
        } else if (dp[i][ind] == nums[i][ind] + dp[i - 1][(ind + 3 - 1) % 3]) {
            ind = (ind + 3 - 1) % 3;
        }
//        std::cout << ind << " ";
        ans += (char)(ind + 'A');
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans;
}
