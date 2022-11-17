/**
 *	author: Lang Dat
 *	create: 05-11-2022 59:46:20
**/
#include <iostream>
#include <unordered_map>
using namespace std;

#define ull unsigned long long
std::unordered_map<int, int> a, b;
ull ans = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CHONDUA.INP", "r", stdin);
    freopen("./CHONDUA.OUT", "w", stdout);
    #endif
    
    int n, tmp;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a[tmp]++;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        b[tmp]++;
    }
    for (const auto &p : a) {
        ans += p.second * (n - b[p.first]);
    }
    std::cout << ans << "";
    return 0;
}