/**
 *	author : Lăng Trọng Đạt
 *	creater: 04-02-2023 08:15:28
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2e5 + 5;
static int a[LIM], diff[LIM], b[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PAIRAB.INP", "r", stdin);
    freopen("./PAIRAB.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += (a[i] + a[j] >= b[i] + b[j]);
    std::cout << ans << "";
}