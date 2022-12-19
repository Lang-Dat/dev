/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 29:38:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./filename.INP", "r", stdin);
    freopen("./filename.OUT", "w", stdout);
    #endif

    int n, prev = 0, ans = 0;
    string str;
    std::cin >> n >> str;
    
    for (char c : str)
        if (c != 'x') prev = 0;
        else if (prev == 2) ans++;
        else prev++;

    std::cout << ans << ""; 
    return 0;
}