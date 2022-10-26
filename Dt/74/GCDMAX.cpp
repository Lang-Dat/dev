/**
 *	author: Lang Dat
 *	create: 25-10-2022 29:16:09
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./GCDMAX.INP", "r", stdin);
    freopen("./GCDMAX.OUT", "w", stdout);
    int t, n;
    std::cin >> t;
    while (std::cin >> n)
    {
        std::cout << n/2 << "\n";
    }
    
    return 0;
}