/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 10:46:06
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 2000 + 5;
static int nums[LIM], dp[LIM], truy[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DAYTANG.INP", "r", stdin);
    freopen("./DAYTANG.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    
    int best = 0, best_pos;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                truy[i] = j;
            }
        }
        if (dp[i] > best) {
            best = dp[i];
            best_pos = i;
        }
    }

    std::vector<int> ans;

    int truy_vet = best_pos;
    while (truy_vet != 0) {
        ans.push_back(truy_vet);
        truy_vet = truy[truy_vet];
    }

    std::cout << best << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
        std::cout << ans[i] << " ";

    return 0;
}