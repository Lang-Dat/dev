/**
 *	author: Lang Dat
 *	create: 07-11-2022 25:30:15
**/
#include <iostream>
using namespace std;

#define ull unsigned long long
const int LIM = 1e3 + 5;
ull nums[LIM], ans = 0, sum = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./sum.INP", "r", stdin);
    freopen("./sum.OUT", "w", stdout);
    #endif

    int n, k, m;
    std::cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    
    m--;
    m %= n;
    for (int i = m; i < n && k > 0; i++, k--)
        ans += nums[i];
    ans += sum * (k / n);
    k %= n;
    for (int i = 0; i < k; i++)
        ans += nums[i];
    std::cout << ans << "";
    return 0;
}