/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 10:14:08
**/
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

static const int LIM = 1e5 + 5;
bitset<LIM> mark;
int n, k, ans = 0;

void solve(int curr, int count) {
    if (count == k) {
        std::cout << "(";
        for (int i = 1, cnt = 0; i <= n; i++)
            if (mark[i]) {
                cnt++;
                std::cout << i;

                if (cnt != k)
                    std::cout << ",";
            }
        std::cout << ")\n";
        ans++;
        return;
    }
    for (int i = curr; i <= n; i++) {
        mark[i] = true;
        solve(i + 1, count + 1);
        mark[i] = false;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHONNGUOI.INP", "r", stdin);
    freopen("./CHONNGUOI.OUT", "w", stdout);

    std::cin >> n >> k;
    solve(1, 0);
    std::cout << ans << "";
    return 0;
}