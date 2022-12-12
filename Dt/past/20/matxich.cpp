/**
 *	author: Lăng Trọng Đạt
 *	create: 11-12-2022 23:02:18
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./matxich.INP", "r", stdin);
    freopen("./matxich.OUT", "w", stdout);
    #endif

    int count = 0;
    char c;
    while (std::cin >> c)    
        count += c == '0';

    std::cout << count << "";

    return 0;
}