/**
 *	author : Lăng Trọng Đạt
 *	creater: 11-01-2023 20:04:31
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1005;
static int a[LIM], b[LIM], dp[LIM][LIM]; // dp[i][j]: dãy con chung dài nhất của b[0:i] và a[0:j]
int n, m;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TEST/TEST/comseq/test01/COMSEQ.INP", "r", stdin);
    freopen("./COMSEQ.OUT", "w", stdout);
    #endif

    std::cin >> m >> n;
    for (int i = 0; i < m; i++)    
        std::cin >> a[i];
    for (int i = 0; i < n; i++)    
        std::cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i] == a[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else 
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    std::cout << dp[n][m] << "\n";
    std::vector<int> ans;
    for (int i = n, j = m; i > 0 and j > 0;) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            ans.push_back(b[i - 1]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        std::cout << ans[i] << " ";
    std::cout << "\n";
    for (int i = ans.size() - 1, j = 0; j < m; j++)
        if (a[j] == ans[i]) {
            std::cout << j + 1 << " ";
            i--;
        }
    std::cout << "\n";
    for (int i = ans.size() - 1, j = 0; j < n; j++) {
        if (b[j] == ans[i]) {
            std::cout << j + 1 << " ";
            i--;
        }
    }

    return 0;
}