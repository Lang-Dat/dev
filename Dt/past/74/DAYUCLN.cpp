/**
 *	author: Lang Dat
 *	create: 26-10-2022 50:50:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYUCLN.INP", "r", stdin);
    freopen("./DAYUCLN.OUT", "w", stdout);

    int n, t, prev, tmp;
    std::cin >> t;
    //int nums[n];
    while (t--)
    {
        std::cin >> n >> prev;
        std::cout << prev << " ";
        for (int i = 1; i < n; i++) {
            std::cin >> tmp;
            cout << (ull)tmp/ __gcd(tmp,prev)*(ull)prev << " ";
            prev = tmp;
        }

        std::cout << tmp << "\n";
    }
    
    return 0;
}