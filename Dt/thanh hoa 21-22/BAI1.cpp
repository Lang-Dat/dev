/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 03:04:16
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    uint64_t n, a, b;
    std::cin >> n >> a >> b;    

    if (a > b) cout << a - b << " ";
    else cout << 0 << " ";
    if (n - a > b) cout << a;
    else cout << a - (b - (n - a));
    
    return 0;
}