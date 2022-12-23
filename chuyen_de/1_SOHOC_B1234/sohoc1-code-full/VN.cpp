/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 28:13:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./VN.INP", "r", stdin);
    freopen("./VN.OUT", "w", stdout);
    #endif

    int a, b;
    std::cin >> a >> b;
    int ucln = __gcd(a, b);
    std::cout << ucln << "\n";
    std::cout << a / ucln << " " << b / ucln;

    return 0;
}