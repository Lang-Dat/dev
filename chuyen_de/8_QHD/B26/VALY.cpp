/**
 *	author : Lăng Trọng Đạt
 *	creater: 09-01-2023 14:59:07
**/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

static const int LIM = 102;
static int p[LIM], v[LIM];
// static int dp[LIM][LIM]; // dp[i][j]: giá trị tối đa khi lấy đến đồ vật thứ i và trọng lượng lớn nhất là j
static int truy[LIM], freq[LIM], dp[LIM]; // dp[i]: giá trị tối đa khi trọng lượng lớn nhất là i
int n, w;

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    freopen("./VALY.INP", "r", stdin);
    // freopen("../B26/TEST/TEST/valy/test01/VALY.INP", "r", stdin);
    freopen("./VALY.OUT", "w", stdout);
    // #endif

    std::cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = p[i]; j <= w; j++) {
            if (v[i] + dp[j - p[i]] > dp[j]) {
                dp[j] = v[i] + dp[j - p[i]];
                truy[j] = i;
            }
        }
    }

    std::cout << dp[w] << "\n";
    int ind = w;
    while (dp[ind - 1] == dp[w])
        ind--;
    while (ind > 0) {
        freq[truy[ind]]++;
        ind = ind - p[truy[ind]];
    }

    for (int i = 1; i < LIM; i++) {
        if (freq[i] != 0) {
            std::cout << i << " " << freq[i] << "\n";
        }
    }
    return 0;
}